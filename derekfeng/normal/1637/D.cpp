#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[103],b[103];
ll f[103][10003];
void sol(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=10000;j++)f[i][j]=1e18;
	int S=0;
	ll ans=0;
	f[0][0]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		ans+=a[i]*a[i]*(n-1),ans+=b[i]*b[i]*(n-1);
		for(int j=0;j<=10000;j++)if(f[i-1][j]<1e18){
			f[i][j+a[i]]=min(f[i][j+a[i]],f[i-1][j]+j*a[i]+(S-j)*b[i]);
			f[i][j+b[i]]=min(f[i][j+b[i]],f[i-1][j]+j*b[i]+(S-j)*a[i]);
		}
		S+=a[i]+b[i];
	}
	ll t=1e18;
	for(int i=0;i<=10000;i++)t=min(t,f[n][i]);
	printf("%lld\n",t*2+ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}