#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int n,mod,C[501][501],A[501][501],g[501][125001],sum1[125005],sum2[125005],ans;
int getsum1(int l,int r){
	if (l>r)return 0;
	int ans=sum1[r];
	if (l>0)ans=(ans-sum1[l-1]+mod)%mod;
	return ans;
}
int getsum2(int l,int r){
	if (l>r)return 0;
	int ans=sum2[r];
	if (l>0)ans=(ans-sum2[l-1]+mod)%mod;
	return ans;
}
signed main(){
    cin>>n>>mod;
    C[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++){
            C[i][j]=C[i-1][j];
            if (j>0)C[i][j]=(C[i][j]+C[i-1][j-1])%mod;
        }
    A[0][0]=1;
    for (int i=1;i<=n;i++)
    	for (int j=0;j<=i;j++){
    		A[i][j]=C[i][j];
    		for (int k=1;k<=j;k++)A[i][j]=A[i][j]*k%mod; 
		}
    g[1][0]=1;
    sum1[0]=1,sum2[0]=0;
    for (int i=2;i<=n;i++){
    	for (int j=0;j<=i*(i-1)/2;j++){
    		g[i][j]=(i+j)*getsum1(j,min(j+i-1,(i-1)*(i-2)/2))%mod;
	  		g[i][j]=(g[i][j]-getsum2(j,min(j+i-1,(i-1)*(i-2)/2))+mod)%mod;
	  		g[i][j]=(g[i][j]+(i-j)*getsum1(max(0ll,j-i+1),min(j-1,(i-1)*(i-2)/2))+getsum2(max(0ll,j-i+1),min(j-1,(i-1)*(i-2)/2)))%mod;
	  		g[i][j]=(g[i][j]+mod)%mod;
	  		if (j+1<i){
				g[i][j]=(g[i][j]+(i-j)*getsum1(1,min(i-1-j,(i-1)*(i-2)/2))-getsum2(1,min(i-1-j,(i-1)*(i-2)/2)))%mod;
				g[i][j]=(g[i][j]+mod)%mod;
			}
    	}
    	memset(sum1,0,sizeof(sum1));
    	memset(sum2,0,sizeof(sum2));
    	for (int j=0;j<=i*(i-1)/2;j++){
    		sum1[j]=g[i][j];
    		if (j>0)sum1[j]=(sum1[j-1]+sum1[j])%mod;
    		sum2[j]=j*g[i][j]%mod;
    		if (j>0)sum2[j]=(sum2[j-1]+sum2[j])%mod;
		}
    }
	for (int i=2;i<=n;i++)
		for (int j=i*(i-1)/2;j>=0;j--)
    		g[i][j]=(g[i][j]+g[i][j+1])%mod;
	for (int i=0;i<n;i++){
		int num=0;
		for (int j=1;j<=n-i;j++)
			for (int k=j+1;k<=n-i;k++)
				ans=(ans+A[n][i]*g[n-i-1][k-j+1])%mod;
	}
	cout<<ans<<endl;
    return 0;
}