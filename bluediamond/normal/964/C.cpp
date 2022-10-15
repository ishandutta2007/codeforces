#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD=1000000009;

ll expow(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b%2)
            ans=(ll)ans*a%MOD;
        a=(ll)a*a%MOD;
        b/=2;
    }
    return ans;
}

int n,k;
ll a,b,sum=0;
ll val;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b>>k;
    if(a==b) {
        int cnt_minus=0;
        int cnt_plus=0;
        string s; cin>>s;
        for(int i=0;i<k;i++) {
            if(s[i]=='-')
                cnt_minus++;
            else
                cnt_plus++;
        }
        cnt_minus*=(n+1)/k;
        cnt_plus*=(n+1)/k;
        ll ori=cnt_plus-cnt_minus;
        ll ans=ori*expow(a,n)%MOD;
        cout<<ans<<"\n";
        return 0;
    }
    ll p1=expow(a,n); ll p2=1;
    string s; cin>>s;
    for(int i=0;i<k;i++) {
        ll semn=1;
        if(s[i]=='-') semn=-1;
        sum+=semn*(p1*p2)%MOD;
        sum%=MOD;
        p1*=expow(a,MOD-2);
        p1%=MOD;
        p2*=b;
        p2%=MOD;
    }
    ll inv=expow(a,MOD-2);
    ll q=expow(b,k)*expow(inv,k)%MOD;
    if(q==1) {
        ll ans=(ll)sum*(n+1)/k%MOD;
        ans%=MOD;
        ans+=MOD;
        ans%=MOD;
        cout<<ans<<"\n";
        return 0;
    }
    ll cnt=(n+1)/k-1;
    ll ans;
    ll sus=expow(q,cnt+1)-1+MOD;
    sus%=MOD;
    ll jos=q-1+MOD;
    jos%=MOD;
    ans=sus*expow(jos,MOD-2)%MOD;
    ans=(ll)ans*sum%MOD;
    ans%=MOD;
    ans+=MOD;
    ans%=MOD;
    cout<<ans<<"\n";
    return 0;
}
/**

1 2 2 1
+

**/