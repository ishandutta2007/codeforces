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
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
int g[maxn],prime[maxn],tot;
inline void prprpr(){
	memset(flag,1,sizeof(flag));
	rep(i,2,1000000){
		if(flag[i])prime[++tot]=i,g[i]=i;
		rep(j,1,tot){
			if(prime[j]*i>1000000)break;
			g[i*prime[j]]=prime[j];flag[i*prime[j]]=0;
			if(i%prime[j]==0)break;
		}
	}
}
int maxi[maxn];
int cnt[maxn];
int main(){
	int n,k;read(n);read(k);prprpr();
	while(k!=1){
		cnt[g[k]]++;k/=g[k];
	}
	rep(i,1,n){
		int x;read(x);
		int lst=0,tme=0;
		while(x!=1){
			if(g[x]==lst){
				tme++;
			}else{
				if(cnt[lst]<=tme)cnt[lst]=0;lst=g[x];tme=1;
			}x/=g[x];
		}if(cnt[lst]<=tme)cnt[lst]=0;
	}
	rep(i,1,1000000)if(cnt[i]){
		puts("No");return 0;
	}puts("Yes");
	return 0;
}