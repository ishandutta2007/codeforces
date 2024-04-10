#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll am[60];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    t-=ll(1)<<(s.back()-'a'),t+=ll(1)<<(s[n-2]-'a');
    for(int i=0;i<n-2;i++)t+=(ll(1)<<(s[i]-'a')),am[s[i]-'a'+1]++;
    ll needed=0;
    for(int i=59;i>=0;i--)needed=max(ll(0),needed+(!!(t&(ll(1)<<i)))-am[i])<<1;
    if(!needed)printf("Yes\n");
    else printf("No\n");
    return 0;
}