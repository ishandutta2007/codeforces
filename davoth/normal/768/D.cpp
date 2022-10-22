#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*ll a[(ll)1e5+10],b[(ll)1e5+10],n,m;
bool check(ll t){
    ll ptr=0;
    for(ll i=0; i<n; i++){
        if(a[i]<=b[ptr]){
            while(ptr<m && b[ptr]-a[i]<=t) ptr++;
        }else{
            if(ptr!=m && a[i]-b[ptr]>t) return false;
            ll d=a[i]-b[ptr],mp1=ptr,mp2=ptr;
            while(mp1<m && (b[mp1]<=a[i] || b[mp1]-b[ptr]+d<=t)) mp1++;
            while(mp2<m && (b[mp2]<=a[i] || b[mp2]-a[i]+b[mp2]-b[ptr]<=t)) mp2++;
            ptr=max(mp1,mp2);
        }
    }
    return ptr==m;
}*/
int main()
{
    /*cin >> n >> m;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<m; i++) cin >> b[i];
    ll l=-1,r=b[m-1]+1;
    while(r-l>1){
        ll md=(l+r)/2;
        if(check(md)) r=md;
        else l=md;
    }
    cout << r << ' ';*/
    //cout << check(3);
    double k, q;
    cin >> k >> q;
    double p[(int)q];
    for(ll i=0; i<q; i++){
        cin >> p[i];
    }
    double dp[10000][(int)k+1];
    dp[1][1]=1;
    for(ll i=2; i<10000; i++){
        for(ll j=1; j<=k; j++){
            dp[i][j]=dp[i-1][j]*(j/k)+dp[i-1][j-1]*(k-j+1)/k;
        }
    }
    for(ll i=0; i<q; i++){
        for(ll j=1; j<10000; j++){
            if(dp[j][(int)k]>=p[i]/2000){
                cout << j << '\n';
                break;
            }
        }
    }
    return 0;
}