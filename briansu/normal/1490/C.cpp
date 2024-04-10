#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const ll M = 1'000'000'000'000LL;

unordered_set<ll> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (ll i = 1; i * i * i <= M; i++)
        st.insert(i * i * i);
    ll T;
    cin >> T;
    while (T--) {
        ll x;
        cin >> x;
        bool fg = false;
        for (ll i = 1; i * i * i < x; i++)
            if (st.count(x - i * i * i)) {
                fg = true;
                break;
            }
        if (fg)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
}