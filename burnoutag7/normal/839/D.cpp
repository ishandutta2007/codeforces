#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n,a[200005],pw[200005];
int cnt[1000005],f[1000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pw[0]=1;
    for(int i=1;i<=2e5;i++)pw[i]=pw[i-1]*2%mod;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int ans=0;
    for(int i=1e6;i>=2;i--){
        int cur=0;
        for(int j=i;j<=1e6;j+=i)cur+=cnt[j];
        f[i]=(ll)cur*pw[cur-1]%mod;
        for(int j=i<<1;j<=1e6;j+=i)f[i]=(f[i]-f[j]+mod)%mod;
        ans=(ans+(ll)f[i]*i)%mod;
    }
    cout<<ans<<endl;

    return 0;
}