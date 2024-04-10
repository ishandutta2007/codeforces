#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
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
/*******************************head*******************************/
const int maxn=200005;
int n,num,head[maxn],t[maxn<<1],ne[maxn<<1],rd[maxn];
int v[maxn];std::vector<int> son[maxn];
int que[maxn],finish,front;
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	// cerr<<x<<' '<<y<<endl;
	rd[y]++;
}
inline void dfs(int x,int f){
	for(int v:son[x]){
		if(f==v)continue;
		dfs(v,x);
	}
	if(v[x]&&f!=-1){
		v[x]^=1;
		addedge(x,f);
	}else if (f!=-1){
		v[f]^=1;
		addedge(f,x);
	}
}
int main(){
	read(n);
	rep(i,1,n)head[i]=-1;
	rep(i,1,n){
		int x;read(x);
		if(x==0)continue;
		int y=i;
		son[x].pb(y);
		son[y].pb(x);
	}
	dfs(1,-1);
	if(v[1]){
		puts("NO");
		return 0;
	}
	rep(i,1,n)if(rd[i]==0)que[++finish]=i;
	while(front!=finish){
		int x=que[++front];
		forE(i,x){
			rd[t[i]]--;
			if(rd[t[i]]==0)que[++finish]=t[i];
		}
	}
	if(finish==n){
		puts("YES");
		rep(i,1,finish)printf("%d\n",que[i]);
	}else{
		puts("NO");
	}
	return 0;
}