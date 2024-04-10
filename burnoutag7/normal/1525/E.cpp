#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int fact[25],inv[25],n,m,d[50005][25],ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0]=inv[0]=fact[1]=inv[1]=1;
    for(int i=2;i<=20;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<=20;i++){
        inv[i]=(ll)inv[i-1]*inv[i]%mod;
    }

    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int cd;
        cin>>cd;
        d[j][cd]++;
    }
    for(int i=1;i<=m;i++){
        int sum=0,cur=1;
        for(int j=n+1;j>1;j--){
            sum+=d[i][j];
            cur=(ll)cur*sum%mod;
            sum--;
        }
        ans=(ans+cur)%mod;
    }
    cout<<(m-(ll)ans*inv[n]%mod+mod)%mod;

    return 0;
}