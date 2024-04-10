#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long 
const int N=5004,mod=1e9+7;
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1<<i)<=r;i++){
		if((1<<i)&r)ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
}
int n,k,ans=0,dwn[N],s[N][N];
int main(){
	n=read();k=read();
	dwn[0]=1;
	for(int i=1;i<=k;i++)dwn[i]=(ll)dwn[i-1]*(n-i+1)%mod;
	s[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)s[i][j]=((ll)s[i-1][j]*j+s[i-1][j-1])%mod;
	for(int i=0;i<=k;i++)
		ans=((ll)s[k][i]*dwn[i]%mod*ksm(2,n-i)+ans)%mod;
	cout<<ans;
	return (0-0);
}