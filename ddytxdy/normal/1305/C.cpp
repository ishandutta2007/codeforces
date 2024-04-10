#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=2e5+50;
int n,m,ans=1,a[N];
int main(){
    scanf("%d%d",&n,&m);if(n>m)puts("0"),exit(0);
    for(int i=1,x;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=1ll*ans*abs(a[i]-a[j])%m;
    cout<<ans;
    return 0;
}