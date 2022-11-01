#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
const int maxn=300005,mod=1e9+7;
int a[maxn],n,pw[maxn];
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	pw[0]=1;
	rep(i,1,n)pw[i]=2ll*pw[i-1]%mod;
	sort(a+1,a+1+n);
	int ans=0,prsum=0;
	rep(i,1,n){
		ans=(ans+1ll*pw[i-1]*a[i])%mod;
		ans=(ans-prsum+mod)%mod;
		ans=(ans-a[i]+mod)%mod;
		prsum=2ll*prsum%mod;
		prsum=(prsum+a[i])%mod;
	}cout<<ans<<endl;
}