#include<bits/stdc++.h>
using namespace std;
long long a[5003][5003],ans;
int power(long long base,long long b)
{
    if (b==0) return 1;
    if (b%2==0){
        long long t=power(base,b/2)%998244353;
        return t%998244353 * t%998244353;
    }
    else{
        long long t=power(base,b/2)%998244353;
        return t%998244353 * t%998244353 * base%998244353;
    }
}
int main()
{
	long long n,m,k;
	cin>>n>>m>>k;
	a[0][0]=1;
	for(int i=1; i<=k; i++) for(int j=1; j<=i; j++) a[i][j]=(a[i-1][j-1]*(n+1-j)+a[i-1][j]*j)%998244353;
	for(int i=1; i<=k; i++) ans+=a[k][i]*power(power(m,998244351),i)%998244353,ans%=998244353;
	cout<<ans;
	return 0;
}