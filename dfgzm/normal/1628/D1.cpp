#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=2010,mod=1e9+7,inv2=(mod+1)/2;
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1; 
	}return ans;
}
int i,j,k,n,m,T;
ll dp[maxn][maxn];
int main(){
	cin>>T;
	for(i=0;i<maxn;i++)dp[i][0]=0;
	for(i=1;i<maxn;i++){
		for(j=0;j<i;j++)
			dp[i][j]=inv2*(dp[i-1][j-1]+dp[i-1][j])%mod;
		dp[i][i]=i;
	}
	while(T--){
		n=read();m=read();k=read();
		printf("%lld\n",k*dp[n][m]%mod);
	}
	return 0;
}