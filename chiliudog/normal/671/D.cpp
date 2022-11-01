#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<i64,int> pin;
const int maxn=300005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
#define pb push_back
vector<int> t[maxn],son[maxn];
i64 f[maxn];
int n,m,dep[maxn];
vector<pin> z[maxn];
i64 ad[maxn];
bool sol=1;
set<pair<i64,int> >Q[maxn];
inline void dfs(int x,int fa){
	for(int v:t[x])if(v!=fa){
		dep[v]=dep[x]+1;dfs(v,x);son[x].pb(v);
	}
}
inline void calc(int x,int fa){
	if(son[x].size()==0){
		ad[x]=0;
		for(pin v:z[x])Q[x].insert(mk(v.w2,v.w1));
		if(Q[x].empty()){
			sol=0;
			f[x]=0;
		}else f[x]=ad[x]+(*(Q[x].begin())).w1;return;
	}i64 sum=0;
	for(int v:son[x])calc(v,x),sum+=f[v];if(!son)return;
	int last=-1;
	for(int v:son[x]){
		ad[v]+=sum-f[v];
		if(last==-1||Q[v].size()>Q[last].size())last=v;
	}
	for(int v:son[x])if(v!=last){
		for(auto w:Q[v]){
			i64 cost=w.w1+ad[v]-ad[last];
			Q[last].insert(mk(cost,w.w2));
		}
	}
	for(pin v:z[x]){
		i64 cost=v.w2+sum-ad[last];
		Q[last].insert(mk(cost,v.w1));
	}
	ad[x]=ad[last];swap(Q[x],Q[last]);
	while(!Q[x].empty()&&Q[x].begin()->w2>=dep[x])Q[x].erase(Q[x].begin());
	if(Q[x].empty()){
		sol=0;return;
	}else{
		f[x]=ad[last]+Q[x].begin()->first;
	}
}
int main(){
    read(n);read(m);
    rep(i,1,n-1){
    	int x,y;read(x);read(y);x--;y--;t[x].pb(y);t[y].pb(x);
    }
    dfs(0,-1);
    rep(i,1,m){
    	int x,y,v;read(x);read(y);read(v);x--;y--;
    	if(x==y)continue;
    	if(dep[x]<dep[y])swap(x,y);
    	z[x].pb(mk(dep[y],v));
    }i64 ans=0;
    for(int v:son[0]){
    	calc(v,0);
    	ans+=f[v];
    }
    if(!sol){
    	puts("-1");return 0;
    }cout<<ans;
    return 0;
}