#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
int fa[N],d[N],f[N],sn[N],n;
int id[N],ans[N],cur,cnt;
vi e[N];

void dfs(int u){
	f[u]=1;
	for(auto v:e[u]){
		dfs(v);
		if(f[v]>f[sn[u]])
			sn[u]=v;
	}
	f[u]=f[sn[u]]+1;
}

int doit(int u,int h){
	if(!h){
		if(sn[u])doit(sn[u],0);
		int rt=sn[u];
		for(auto v:e[u])
			if(v!=sn[u]){
				ans[++cnt]=rt;
				rt=doit(v,rt);
			}
		id[++cur]=u;
		return u;
	}
	int rt=h;
	for(auto v:e[u]){
		ans[++cnt]=rt;
		rt=doit(v,rt);
	}
	id[++cur]=u;
	return u;
}

int main(){
	read(n);
	rep(i,2,n){
		read(fa[i]);
		fa[i]++;
		e[fa[i]].pb(i);
	}
	d[1]=1,dfs(1);
	doit(1,0);
	reverse(id+1,id+cur+1);
	rep(i,1,cur) printf("%d ",id[i]-1);
	puts("");
	reverse(ans+1,ans+cnt+1);
	printf("%d\n",cnt);
	rep(i,1,cnt) printf("%d ",ans[i]-1);
	puts("");
	return 0;
}