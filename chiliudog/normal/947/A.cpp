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
const int maxn=1000005;
bool flag[maxn];
int pr[maxn],tot;
int fac[maxn];
bool vis[maxn];
inline void prprpr(){
	memset(flag,1,sizeof(flag));fac[1]=1;
	rep(i,2,1000000){
		if(flag[i])pr[++tot]=i,fac[i]=i;
		rep(j,1,tot){
			if(i*pr[j]>1000000)break;
			fac[i*pr[j]]=pr[j];
			flag[i*pr[j]]=0;
			if(i%pr[j]==0)break;
		}
	}
}
inline int calc(int x){
	if(vis[x])return -1e9;
	vis[x]=1;
	int prx=x,ans=1e9;
	while(x!=1){
		int v=fac[x];
		if(v==prx){
			break;
		}
		int res=(prx/v-1)*v+1;
		ans=min(ans,res);
		x/=v;
	}return ans;
}
int main(){
	prprpr();
	int n;read(n);
	int prn=n,ans=1e9;
	while(n!=1){
		int v=fac[n];
		if(prn==v){
			break;
		}
		int mini=(prn/v-1)*v+1;
		rep(i,mini,prn){
			int res=calc(i);
			if(res==-1e9)break;
			if(res>=3)ans=min(ans,res);
		}
		n/=fac[n];
	}cout<<ans<<endl;
	return 0;
}