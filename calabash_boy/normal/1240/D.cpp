#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
typedef unsigned long long ULL;
ULL seed = 146527;
ULL seed2 = 1234567;
ULL mod = 1e9 + 7;
ULL mod2 = 998244353;
int a[maxn];
void solve(){
    int n;
    cin>>n;
    stack<pair<int,pair<ULL,ULL> > > stk;
    stk.push(make_pair(-1,make_pair(0,0)));
    map<pair<ULL,ULL>,int> cnt;
    cnt[make_pair(0,0)]++;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (stk.top().first == x){
            stk.pop();
        }else{
            ULL hash1 = stk.top().second.first * seed % mod + x;
            ULL hash2 = stk.top().second.second * seed2 % mod2 + x;
            hash2 %= mod2;
            hash1 %= mod;
            stk.push(make_pair(x,make_pair(hash1,hash2)));
        }
        cnt[stk.top().second] ++;
    }
    long long ans = 0;
    for (auto pr : cnt){
        int num = pr.second;
        ans += 1ll * num * (num-1) / 2;
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
    return 0;
}