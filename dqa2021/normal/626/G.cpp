#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
//#include<assert.h>
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
typedef long double ld;
const ld eps=1e-10L;

int n,T,q; ld ans;
int p[200010],l[200010],c[200010];
struct Rec{
	ld d; int id;
};
typedef set<Rec>::iterator It;
bool operator<(Rec x,Rec y){
	if (fabs(x.d-y.d)>eps) return x.d<y.d;
	return x.id<y.id;
}
set<Rec> A,B;  //ins del
ld getval(int a,int b,int p){return 1.0L*a*p/(a+b);}
void ins(int u){
	/*if (c[u]+1<=l[u])*/ A.erase((Rec){getval(c[u]+1,l[u],p[u])-getval(c[u],l[u],p[u]),u});
	if (c[u]) B.erase((Rec){getval(c[u],l[u],p[u])-getval(c[u]-1,l[u],p[u]),u});
	//assert(c[u]+1<=l[u]);
	c[u]++; ans+=getval(c[u],l[u],p[u])-getval(c[u]-1,l[u],p[u]);
	B.insert((Rec){getval(c[u],l[u],p[u])-getval(c[u]-1,l[u],p[u]),u});
	if (c[u]+1<=l[u]) A.insert((Rec){getval(c[u]+1,l[u],p[u])-getval(c[u],l[u],p[u]),u});
}
void del(int u){
	if (c[u]+1<=l[u]) A.erase((Rec){getval(c[u]+1,l[u],p[u])-getval(c[u],l[u],p[u]),u});
	/*if (c[u])*/ B.erase((Rec){getval(c[u],l[u],p[u])-getval(c[u]-1,l[u],p[u]),u});
	//assert(c[u]>0);
	c[u]--; ans+=getval(c[u],l[u],p[u])-getval(c[u]+1,l[u],p[u]);
	A.insert((Rec){getval(c[u]+1,l[u],p[u])-getval(c[u],l[u],p[u]),u});
	if (c[u]) B.insert((Rec){getval(c[u],l[u],p[u])-getval(c[u]-1,l[u],p[u]),u});
}
int main()
{

	n=read(),T=read(),q=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) l[i]=read();
	for (int i=1;i<=n;i++) A.insert((Rec){getval(1,l[i],p[i]),i});
	while (T){
		if (A.empty()) break;
		T--; ins(A.rbegin()->id);
	}
	while (q--){
		int t=read(),x=read();
		if (t==1){
			if (c[x]+1<=l[x]) A.erase((Rec){getval(c[x]+1,l[x],p[x])-getval(c[x],l[x],p[x]),x});
			if (c[x]) B.erase((Rec){getval(c[x],l[x],p[x])-getval(c[x]-1,l[x],p[x]),x});
			ans-=getval(c[x],l[x],p[x]);
			l[x]++;
			ans+=getval(c[x],l[x],p[x]);
			if (c[x]+1<=l[x]) A.insert((Rec){getval(c[x]+1,l[x],p[x])-getval(c[x],l[x],p[x]),x});
			if (c[x]) B.insert((Rec){getval(c[x],l[x],p[x])-getval(c[x]-1,l[x],p[x]),x});
			if (!A.empty()&&!B.empty()&&B.begin()->d+eps<A.rbegin()->d){
				int u=B.begin()->id,v=A.rbegin()->id;
				del(u); ins(v);
			}
			if (T&&!A.empty()) T--,ins(A.rbegin()->id);
		}
		else{
			if (c[x]+1<=l[x]) A.erase((Rec){getval(c[x]+1,l[x],p[x])-getval(c[x],l[x],p[x]),x});
			if (c[x]) B.erase((Rec){getval(c[x],l[x],p[x])-getval(c[x]-1,l[x],p[x]),x});
			ans-=getval(c[x],l[x],p[x]);
			l[x]--; if (c[x]>l[x]) c[x]=l[x],T++;
			ans+=getval(c[x],l[x],p[x]);
			if (c[x]+1<=l[x]) A.insert((Rec){getval(c[x]+1,l[x],p[x])-getval(c[x],l[x],p[x]),x});
			if (c[x]) B.insert((Rec){getval(c[x],l[x],p[x])-getval(c[x]-1,l[x],p[x]),x});
			if (!A.empty()&&!B.empty()&&B.begin()->d+eps<A.rbegin()->d){
				int u=B.begin()->id,v=A.rbegin()->id;
				del(u); ins(v);
			}
			if (T&&!A.empty()) T--,ins(A.rbegin()->id);
		}
		printf("%.10lf\n",(double)ans);
	}
	return 0;
}