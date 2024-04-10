#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*ll a[(ll)1e5+10],b[(ll)1e5+10],n,m;
bool check(ll t){
    ll ptr=0;
    for(ll i=0; i<n; i++){
        if(a[i]<=b[ptr]){
            for(; ptr<m && b[ptr]-a[i]<=t; ptr++) continue;
        }else{
            if(a[i]-b[ptr]>t) return false;
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
    cout << r;
    cout << check(2);*/
    ll n;
    cin >> n;
    ll a[n],b[n],c[n];
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) cin >> b[i];
    for(ll i=0; i<n; i++) cin >> c[i];
    ll dp[n][2];
    dp[0][1]=b[0];
    dp[0][0]=a[0];
    for(ll i=1; i<n; i++){
        dp[i][0]=max(dp[i-1][0]+b[i],dp[i-1][1]+a[i]);
        dp[i][1]=max(dp[i-1][1]+b[i],dp[i-1][0]+c[i]);
    }
    cout << dp[n-1][0];
    return 0;
}