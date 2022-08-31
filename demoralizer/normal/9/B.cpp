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
    ll n,b,s;
    cin>>n>>b>>s;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll x,y;
    cin>>x>>y;
    set<pair<pair<double,double>,ll> >z;
    for(ll i=1;i<n;i++){
        z.insert({{1.0*a[i]/b+1.0*sqrt((x-a[i])*(x-a[i])+y*y)/s,(x-a[i])*(x-a[i])+y*y},i+1});
    }
    cout<<(*z.begin()).sc;
}