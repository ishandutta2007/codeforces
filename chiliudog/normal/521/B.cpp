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
map<pin,int> zb;
const int maxn=100005;
const int mod=1e9+9;
vector<int> tr[maxn];
vector<int> fa[maxn];
set<int> avi;
int x[maxn],y[maxn],n,rd[maxn],cnt[maxn];
bool used[maxn];
int ans=0;
inline int getmax(){
	set<int>::iterator It=avi.end();
	It--;
	return *It;
}
inline int getmin(){
	return *avi.begin();
}
int main(){
  	//judge();
    read(n);
    rep(i,1,n)read(x[i]),read(y[i]);
    rep(i,1,n)zb[mk(x[i],y[i])]=i;
    rep(i,1,n)avi.insert(i);
    rep(i,1,n){
    	if(zb.count(mk(x[i]-1,y[i]-1))){
    		tr[i].pb(zb[mk(x[i]-1,y[i]-1)]);
    		rd[zb[mk(x[i]-1,y[i]-1)]]++;
    		fa[zb[mk(x[i]-1,y[i]-1)]].pb(i);
    		cnt[i]++;
    	}
    	if(zb.count(mk(x[i],y[i]-1))){
    		tr[i].pb(zb[mk(x[i],y[i]-1)]);
    		rd[zb[mk(x[i],y[i]-1)]]++;
    		fa[zb[mk(x[i],y[i]-1)]].pb(i);
    		cnt[i]++;
    	}
    	if(zb.count(mk(x[i]+1,y[i]-1))){
    		tr[i].pb(zb[mk(x[i]+1,y[i]-1)]);
    		fa[zb[mk(x[i]+1,y[i]-1)]].pb(i);	
    		rd[zb[mk(x[i]+1,y[i]-1)]]++;
    		cnt[i]++;
    	}
    	if(cnt[i]==1)avi.erase(tr[i][0]);
    }
    rep(T,1,n){
    	int x;
    	if(T&1)
    		x=getmax();
    	else
    		x=getmin();
    	avi.erase(x);used[x]=1;
    	for(int v:tr[x]){
    		rd[v]--;
    		if(used[v])continue;
    		avi.insert(v);
    		if(rd[v]==0&&!used[v])avi.insert(v);
    		for(int fk:fa[v]){
    			if(used[fk])continue;
    			if(cnt[fk]==1)avi.erase(v);
    		}
    	}
    	for(int v:fa[x]){
    		if(used[v])continue;
    		cnt[v]--;if(cnt[v]==1){
    			for(int fk:tr[v])avi.erase(fk);
    		}
    	}
    	ans=1ll*n*ans%mod;
    	ans+=(x-1);//printf("%d\n",x);
    }cout<<ans%mod;
    return 0;
}