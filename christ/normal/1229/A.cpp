#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
map<ll,int> freq;
int main() {
    int n;
    scanf ("%d",&n);
    vector<ll> a(n); vector<int> b(n); ll ret = 0;
    for (auto &au : a) scanf ("%lld",&au), ++freq[au];
    for (auto &au : b) scanf ("%d",&au);
    vector<int> good; vector<ll> mask;
    for (auto &au : freq) if (au.second > 1) {
        vector<int> can; mask.push_back(au.first);
        for (int i = 0; i < n; i++) if (a[i] == au.first) can.push_back(b[i]);
        sort(all(can));
        for (auto &au : can) ret += au;
    }
    for (int i = 0; i < n; i++) if (freq[a[i]] == 1) {
        bool ok = 0;
        for (ll m : mask) ok |= (m&a[i])==a[i];
        if (ok) ret += b[i];
    }
    printf ("%lld\n",ret);
    return 0;
}