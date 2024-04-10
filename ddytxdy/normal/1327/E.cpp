#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=998244353;
int n,pw[N];
int main(){
    scanf("%d",&n);pw[0]=1;
    for(int i=1;i<=n;i++)pw[i]=10ll*pw[i-1]%mod;
    for(int i=1;i<=n;i++){
        int x=max(n-i-1,0)*810ll%mod*pw[max(n-i-2,0)]%mod;
        if(i!=n)x=(x+180ll*pw[n-i-1])%mod;
        else x=(x+10)%mod;
        printf("%d ",x);
    }
    return 0;
}