#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll s,k,l=1;
    cin>>s>>k;
    vc<ll> v,u;
    u.pb(0);
    v.pb(1);
    while(1==1){
        ll x=0;
        for(ll i=l-1;(i>=0)&&(l-i<=k);i--)x+=v[i];
        if(x>s)break;
        v.pb(x);
        l++;
    }
    l--;
    while(s>0){
        while(v[l]>s)l--;
        s-=v[l];
        u.pb(v[l]);
    }
    cout<<u.size()<<"\n";
    for(ll i=0;i<u.size();i++) cout<<u[i]<<" ";
}