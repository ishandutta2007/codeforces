#include<cstdio>
#include<algorithm>
#include<cctype>
#include<set>
#include<vector>
#define pb push_back
#define forall(x,i) for (int i=0;i<x.size();i++)
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
typedef unsigned long long ull;

int n,k,m=1e9; int L[300010],R[300010];
struct Rec{
	int l,r,c;
};
bool operator<(Rec x,Rec y){return x.l<y.l;}
set<Rec> st;
typedef set<Rec>::iterator It;
vector<Rec> rec[300010];
int bin[300010]; int p; int S;
void ins(int x,int v){
	if (p<=x) S+=v;
	bin[x]+=v;
}
ull tri[300010];
inline void add(int x,ull v){
	if (!x) return;
	for (;x<=n;x+=x&-x) tri[x]+=v;
}
inline ll ask(int x){
	ull res=0;
	for (;x;x-=x&-x) res+=tri[x];
	return res;
}
void _ins(int x,int v){
	if (p<=x) S+=v;
	bin[x]+=v;
	add(x,1LL*v*x);
}
ll check(int x){
	p=0; S=m; ll res=0; for (int i=0;i<=n;i++) bin[i]=0; bin[0]=m;
	for (int i=1;i<=n;i++){
		forall(rec[i],j){
			int l=rec[i][j].l,r=rec[i][j].r,c=rec[i][j].c;
			ins(c,-r+l-1); ins(i,r-l+1);
		}
		while (p<i&&S-bin[p]>=x) S-=bin[p++];
		res+=p;
	}
	return res;
}
ll work(int x){
	p=0; S=m; ll res=0; for (int i=0;i<=n;i++) bin[i]=0; bin[0]=m;
	for (int i=1;i<=n;i++){
		forall(rec[i],j){
			int l=rec[i][j].l,r=rec[i][j].r,c=rec[i][j].c;
			_ins(c,-r+l-1); _ins(i,r-l+1);
		}
		while (p<i&&S-bin[p]>=x) S-=bin[p++];
		if (p) res+=1LL*S*p+ask(p-1);
	}
	return res;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	n=read(),k=read();
	for (int i=1;i<=n;i++) L[i]=read(),R[i]=read()-1;
	st.insert((Rec){1,m,0});
	for (int i=1;i<=n;i++){
		It u=st.upper_bound((Rec){L[i],0,0}); --u;
		if (u->l!=L[i]){
			int l=u->l,r=u->r,c=u->c;
			st.erase(u);
			st.insert((Rec){l,L[i]-1,c});
			st.insert((Rec){L[i],r,c});
		}
		u=st.upper_bound((Rec){R[i],0,0}); --u;
		if (u->r!=R[i]){
			int l=u->l,r=u->r,c=u->c;
			st.erase(u);
			st.insert((Rec){l,R[i],c});
			st.insert((Rec){R[i]+1,r,c});
		}
		u=st.lower_bound((Rec){L[i],0,0});
		It v=st.upper_bound((Rec){R[i],0,0});
		for (It it=u;it!=v;it++) rec[i].pb(*it);
		st.erase(u,v); st.insert((Rec){L[i],R[i],i});
	}
	int l=1,r=m,mid;
	while (l<r){
		mid=l+r>>1;
		if (check(mid)<k) r=mid;
		else l=mid+1;
	}
	ll ans=1LL*(k-check(l))*(l-1)+work(l);
	printf("%lld\n",ans);
	return 0;
}