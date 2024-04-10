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
const int mod=1e9+9;
const int maxn=1000005;
int a,b,n,k;
char str[maxn];
int s[maxn];
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
	}return res;
}
int main(){
	read(n);read(a);read(b);read(k);
	scanf("%s",str+1);
	rep(i,0,k-1)s[i]=(str[i+1]=='+')?1:-1;
	int p=0,x=0;
	rep(i,0,k-1){
		p=(p+1ll*powmod(a,n-i)*powmod(b,i)*s[i]%mod+mod)%mod;
	}
	x=1ll*powmod(b,k)*powmod(powmod(a,mod-2),k)%mod;
	int res=0,m=(n+1)/k-1;
	// cerr<<p<<endl;
	// cerr<<x<<' '<<a<<' '<<m<<endl;
	if(x==1){
		res=1ll*(m+1)*p%mod;
	}else{
		res=(1ll*powmod(x,m+1)*p-p+mod)%mod;
		res=1ll*res*powmod(x-1,mod-2)%mod;
		res=(res+mod)%mod;
	}
	cout<<res<<endl;
	return 0;
}