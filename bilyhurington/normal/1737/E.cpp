#include<bits/stdc++.h>
using namespace std;
int T,n,f[1000010],g[1000010];
long long pw2[1000010];
const int mod=1e9+7;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);pw2[0]=1;
        if(n==1){puts("1");continue;}
        for(int i=1;i<=n;i++) pw2[i]=pw2[i-1]*((mod+1)/2)%mod;
        for(int i=2;i<=n;i++) f[i]=pw2[(i+1)/2-(i==n)];
        long long sum=1;
        for(int i=n,j=n;i>=1;i--){
            while(j>=2*i){
                sum=(sum-g[j]+mod)%mod;
                j--;
            }g[i]=sum*f[i]%mod;
        }
        for(int i=1;i<=n;i++) printf("%d\n",g[i]);
    }
    return 0;
}