#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[5003],lst;
ll f[5003][5003];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=1e18;
	for(int i=0;i<=n;i++)f[0][i]=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1){
			for(int j=1;j<=n;j++){
				f[i][j]=f[i][j-1];
				if(a[j]==0)f[i][j]=min(f[i][j],f[lst][j-1]+abs(j-i));
			}
			lst=i;
		}
	printf("%lld",f[lst][n]);
}