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
const int mod=1e9+7;
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
int cnt[2312];
const int maxn=100005;
char s[maxn];
inline int C(int n,int m){
	//if(m==0)return 1;
	int res=1;
	per(i,n,n-m+1)res=1ll*res*i%mod;
	rep(i,1,m)res=1ll*res*powmod(i,mod-2)%mod;
	return res;
}
int main(){
    int n;read(n);
    scanf("%s",s+1);
    rep(i,1,n)cnt[s[i]]++;
    int maxi=0;
    rep(i,'A','Z')maxi=max(maxi,cnt[i]);
    int tot=0;
    rep(i,'A','Z')if(cnt[i]==maxi)tot++;
    printf("%d\n",powmod(tot,n));
    return 0;
}