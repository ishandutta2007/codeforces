#include <bits/stdc++.h>
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
const int maxn=100005;
char s[maxn],t[maxn];
int n,m,last[maxn];
bool flag[maxn];
int f[maxn],sum[maxn],prsum[maxn];
const int mod=1e9+7;
inline void prprpr(){
	int j=0;
	rep(i,2,m){
		while(j&&t[j+1]!=t[i])j=last[j];
		if(t[j+1]==t[i])j++;
		last[i]=j;
	}j=0;
	rep(i,1,n){
		while(j&&t[j+1]!=s[i])j=last[j];
		if(t[j+1]==s[i])j++;
		if(j==m){
			flag[i]=1;
			j=last[j];
		}
	}
}
int main(){
    scanf("%s",s+1);scanf("%s",t+1);
    n=strlen(s+1);m=strlen(t+1);
    prprpr();
    int lst=-1;sum[0]=1;prsum[0]=1;
    rep(i,1,n){
    	if(flag[i]){
    		lst=i-m;
    	}
    	if(lst>=0)f[i]=prsum[lst];
    	sum[i]=(sum[i-1]+f[i])%mod;
    	prsum[i]=(prsum[i-1]+sum[i])%mod;
    }sum[n]-=1;if(sum[n]<0)sum[n]+=mod;
    cout<<sum[n]<<endl;
    return 0;
}