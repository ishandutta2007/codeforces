#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000006

int arr[MAXN];
vector<int> primes;
int lp[MAXN];

void init(){
    for(int i = 2; i<MAXN; i++){
        if(lp[i] == 0) lp[i] = i, primes.push_back(i);
        for(int j = 0; j<primes.size() && primes[j]<=lp[i] && i*primes[j] < MAXN; j++) lp[i*primes[j]] = primes[j];
    }
    for(int i = 1; i<MAXN; i++) arr[i] = i;
    for(int i = 1; i<MAXN; i++) for(int j = 0; j<primes.size() && 1ll*i*primes[j]*primes[j] < MAXN; j++) arr[i*primes[j]*primes[j]] = arr[i];
    
}

void solve(){
    int n; cin >> n; map<int, int> mp;
    for(int i = 0; i<n; i++){
        int a; cin >> a; mp[arr[a]]++;
    }
    int mx1 = mp[1], sumeven = 0, mxodd = 0, maxall = 0;
    for(auto p : mp){
        maxall = max(maxall, p.second);
        if(p.first == 1) continue;
        if(p.second%2) mxodd = max(mxodd, p.second);
        else sumeven += p.second;
    }
    int q; cin >> q;
    while(q--){
        long long a; cin >> a;
        if(a > 0ll) cout << max(mx1+sumeven, mxodd) << endl;
        else cout << maxall << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    init();
    while(t--){
        solve();
    }
}