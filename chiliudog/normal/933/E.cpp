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
const int maxn=500005;
int a[maxn],n;
i64 f[maxn],g[maxn];
vector<int> ans,tans;
inline void get(int x){
	if(x<0)return;
	if(g[x]==f[x]){
		ans.pb(x-1);
		ans.pb(x);
		get(x-2);
		return;
	}
	if(a[x-1]>=a[x]){
		if(g[x]==f[x-1]){
			ans.pb(x-1);
			ans.pb(x-2);
			get(x-3);
		}else assert(0);
	}else{
		if(a[x]<=a[x-1]+a[x+1]){
			if(g[x]==f[x-1]+a[x]-a[x-1]){
				ans.pb(x-1);
				ans.pb(x);
				get(x-3);
			}else{
				assert(0);
			}
		}else{
			assert(0);
		}
	}
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n){
		f[i]=((i-2)>=0?(g[i-2]):0)+a[i];
		g[i]=f[i];
		if(a[i-1]>=a[i])g[i]=min(g[i],f[i-1]);
		else{
			if(a[i]<=a[i-1]+a[i+1])
				g[i]=min(g[i],f[i-1]+a[i]-a[i-1]);
		}
	}
	i64 val=min(g[n],g[n-1]);
	if(val==g[n])get(n);
	else get(n-1);
	int cnt=0;
	for(u32 i=0;i<ans.size();i++){
		int v=ans[i];
		if(v<=0)continue;
		if(a[v]&&a[v+1]){
			cnt++;tans.pb(v);
			int res=min(a[v],a[v+1]);
			a[v]-=res;a[v+1]-=res;
		}
	}printf("%d\n",cnt);
	for(u32 i=0;i<tans.size();i++){
		int v=tans[i];if(v>0)printf("%d\n",v);
	}
	return 0;
}