#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
#define forall(x,i) for (int i=0;i<x.size();i++)
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
void print(int x){
	if (x>9) print(x/10); putchar((x%10)^48);
}
#undef G
const int N=1<<12,Q=1<<16,S=1<<8,T=2.2e6;
int a[T+10],b[T+10],m;
int merge(int x,int y){
	if(!x||!y) return x|y;
	a[++m]=x,b[m]=y; return m;
}

int n,q;
int p[N+10],ip[N+10];
int tab[N+10][N+10];
struct Rec{
	int l,r,id;
};
typedef vector<Rec> V;
bool operator<(Rec x,Rec y){
	if (x.l^y.l) return x.l<y.l;
	return x.r<y.r;
}
struct B{
	V solve(int l,int r){
		V res;
		if (l==r) return res.pb((Rec){ip[l],ip[r],ip[l]+1}),res;
		int mid=l+r>>1;
		V L=solve(l,mid),R=solve(mid+1,r);
		inplace_merge(ip+l,ip+mid+1,ip+r+1);
		res.reserve((r-l+1)*(r-l+2)/2);
		int Sl=L.size(),Sr=R.size();
		for (int i=l;i<=r;i++){
			int pl=lower_bound(L.begin(),L.end(),(Rec){ip[i],0,0})-L.begin()-1,_pl=pl;
			int pr=lower_bound(R.begin(),R.end(),(Rec){ip[i],0,0})-R.begin()-1,_pr=pr;
			for (int j=i;j<=r;j++){
				while (pl+1<Sl&&L[pl+1].l==L[_pl+1].l&&L[pl+1].r<=ip[j]) pl++;
				while (pr+1<Sr&&R[pr+1].l==R[_pr+1].l&&R[pr+1].r<=ip[j]) pr++;
				int k=merge(pl==_pl?0:L[pl].id,pr==_pr?0:R[pr].id);
				res.pb((Rec){ip[i],ip[j],k});
			}
		}
		return res;
	}
	void work(int l,int r){
		V res=solve(l,r);
		forall(res,i){
			int x=res[i].l,y=res[i].r,id=res[i].id;
			tab[x][y]=id;
		}
	}
	int getans(int l,int r,int L,int R){
		int x=lower_bound(ip+L,ip+R+1,l)-ip;
		int y=upper_bound(ip+L,ip+R+1,r)-ip-1;
		if (x>y) return 0;
		return tab[ip[x]][ip[y]];
	}
}B[N/S+10];
int ans[Q+10];
int main()
{
	n=read(),q=read(); m=n;
	for (int i=0;i<n;i++){
		p[i]=read()-1;
		ip[p[i]]=i;
	}
	for (int i=0,t=0;i<n;i+=S,t++) B[t].work(i,min(i+S,n)-1);
	for (int i=1;i<=q;i++){
		int l=read()-1,r=read()-1;
		for (int j=0,t=0;j<n;j+=S,t++) ans[i]=merge(ans[i],B[t].getans(l,r,j,min(j+S,n)-1));
	}
	printf("%d\n",m);
	for (int i=n+1;i<=m;i++) print(a[i]),putchar(' '),print(b[i]),putchar('\n');
	for (int i=1;i<=q;i++) print(ans[i]),putchar(' '); putchar('\n');
	return 0;
}