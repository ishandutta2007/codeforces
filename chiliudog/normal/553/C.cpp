#include<bits/stdc++.h>
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
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
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
int n,m;const int maxn=100005;
int a[maxn],b[maxn],c[maxn],v[maxn];
bool sure[maxn];

vector<pin> son[maxn];
bool vis[maxn],invalid;
inline void dfs(int x){
	vis[x]=1;
	for(pin w:son[x]){
		if(vis[w.w1]){
			if(v[x]^v[w.w1]^w.w2)invalid=1;
		}else{
			v[w.w1]=v[x]^w.w2;
			dfs(w.w1);
		}
	}
}const int mod=1e9+7;
int main(){
    read(n);read(m);invalid=0;//szsz.init();
    rep(i,1,m){
    	read(a[i]);read(b[i]);read(c[i]);
    	c[i]^=1;if(a[i]>b[i])swap(a[i],b[i]);
    	son[a[i]].pb(mk(b[i],c[i]));
    	son[b[i]].pb(mk(a[i],c[i]));
    }int ans=1;
    rep(i,1,n){
    	if(!vis[i]){
    		dfs(i);if(i!=1)ans=2*ans%mod;
    	}
    }if(invalid)ans=0;
    cout<<ans;
    return 0;
}