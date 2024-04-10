// Problem: CF1213G Path Queries
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1213G
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=2e5+100;
int n,m;int u[N],v[N],w[N];ll tmp,ans[N];
vector<int>qry[N],id[N];
int fa[N],sz[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	fa[x]=y;
	tmp-=1ll*sz[x]*(sz[x]-1);
	tmp-=1ll*sz[y]*(sz[y]-1);
	sz[y]+=sz[x];
	tmp+=1ll*sz[y]*(sz[y]-1);
}
signed main(){
	read(n,m);
	for(int i=1;i<n;i++){
		read(u[i],v[i],w[i]);
		id[w[i]].pb(i);
	}
	for(int i=1,q;i<=m;i++)
		read(q),qry[q].pb(i);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=200000;i++){
		for(auto j:id[i])merge(u[j],v[j]);
		for(auto j:qry[i])ans[j]=tmp;
	}
	for(int i=1;i<=m;i++)write(ans[i]/2),putchar(' ');
}