#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int B=548;
const int ML=B*B;

int n,q,mod,a[300005],f[300005],cnt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q>>mod;
    f[1]=1;
    for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b;
        cin>>b;
        a[i]=(a[i]-b+mod)%mod;
    }
    for(int i=n;i>=2;i--){
        a[i]=((ll)a[i]-a[i-1]-a[i-2]+mod*2)%mod;
        cnt+=!!a[i];
    }
    cnt+=!!a[1];
    while(q--){
        char typ;
        int l,r;
        cin>>typ>>l>>r;
        cnt-=!!a[l];
        if(r+1<=n)cnt-=!!a[r+1];
        if(r+2<=n)cnt-=!!a[r+2];
        a[l]=(a[l]+(typ=='A'?1:mod-1))%mod;
        if(r+1<=n)a[r+1]=(a[r+1]+(typ=='A'?mod-f[r-l+2]:f[r-l+2]))%mod;
        if(r+2<=n)a[r+2]=(a[r+2]+(typ=='A'?mod-f[r-l+1]:f[r-l+1]))%mod;
        cnt+=!!a[l];
        if(r+1<=n)cnt+=!!a[r+1];
        if(r+2<=n)cnt+=!!a[r+2];
        cout<<(!cnt?"YES\n":"NO\n");
    }

    return 0;
}