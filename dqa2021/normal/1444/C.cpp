#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<iostream> 
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef pair<int,int> P; 
typedef long long ll;

int n,m,k;
int c[500010];
struct Rec{
	int x,y,u,v;
}r[500010]; int top;
bool operator<(Rec x,Rec y){
	if (x.x^y.x) return x.x<y.x;
	return x.y<y.y;
}

int f[1000010],dep[1000010];
int find(int x){return f[x]?find(f[x]):x;}
struct D{
	int *x,v;
};
void merge(int x,int y,vector<D> &d){
	x=find(x),y=find(y);
	if (x==y) return;
	if (dep[x]<dep[y]) swap(x,y);
	d.pb((D){&f[y],f[y]});
	d.pb((D){&dep[x],dep[x]});
	f[y]=x,dep[x]=max(dep[x],dep[y]+1);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return;
	if (dep[x]<dep[y]) swap(x,y);
	f[y]=x,dep[x]=max(dep[x],dep[y]+1);
}

bool mrk[500010];

P g[500010]; int gtot;

int main()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		if (c[x]==c[y]){
			merge(x,y+n); merge(x+n,y);
		}
		else{
			if (c[x]>c[y]) swap(x,y);
			r[++top]=(Rec){c[x],c[y],x,y};
		}
	}
	for (int i=1;i<=n;i++) if (find(i)==find(i+n)) mrk[c[i]]=1;
	sort(r+1,r+top+1);
	for (int i=1,j;i<=top;i=j+1){
		for (j=i;j<top&&r[j+1].x==r[j].x&&r[j+1].y==r[j].y;j++);
		if (mrk[r[i].x]||mrk[r[i].y]) continue;
		vector<D> d;
		for (int u=i;u<=j;u++){
			int x=r[u].u,y=r[u].v;
			merge(x,y+n,d); merge(x+n,y,d);
		}
		for (int u=i;u<=j;u++){
			int x=r[u].u,y=r[u].v;
			if (find(x)==find(x+n)||find(y)==find(y+n)){
//				if ()
				g[++gtot]=(P){c[x],c[y]};
				break;
			}
		}
		reverse(d.begin(),d.end());
		for (auto x: d) *x.x=x.v;
	}
	ll ans=0;
	for (int i=1;i<=k;i++) ans+=!mrk[i];
	ans=ans*(ans-1)/2;
	sort(g+1,g+gtot+1); gtot=unique(g+1,g+gtot+1)-g-1;
	ans-=gtot;
	cout<<ans;
}