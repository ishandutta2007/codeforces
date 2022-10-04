#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <functional>
#define ll long long
#define null NULL
#define all(a) a.begin(), a.end()

using namespace std;

const ll MOD = 1e9 + 7;

const ll mx = 3e5;
const ll lg = 62;
ll n, a[mx];
vector<vector<ll> > v;
vector<ll> cur;

ll get_max_bit(ll x) {
    for (ll i = lg - 1; i >= 0; --i) {
        if ((x >> i) & 1)
            return i;
    }
    return -1;
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    v.resize(lg);
    for (ll i = 0; i < n; ++i) {
        v[get_max_bit(a[i])].push_back(a[i]);
    }
    for (ll i = lg - 1; i >= 0; --i) {
        vector<ll> pos;
        ll cs = cur.size();
        for (ll j = 0; j < cs; ++j) {
            if ((cur[j] >> i) & 1)
                pos.push_back(j);
        }
        if (pos.size() == 0)
            pos.push_back(0);
        else {
            pos.push_back(pos.back() + 1);
        }
        if (pos.size() < v[i].size()) {
            cout << "No" << endl;
            return 0;
        }
        pos.resize(v[i].size());
        ll ptr = 0;
        vector<ll> new_cur;
        for (ll j = 0; j <= cs; ++j) {
            if (ptr < pos.size() && pos[ptr] == j) {
                new_cur.push_back(v[i][ptr]);
                ptr++;
            }
            if (j < cs) {
                new_cur.push_back(cur[j]);
            }
        }
        cur = new_cur;
    }
    cout << "Yes" << endl;
    for (auto x : cur) {
        cout << x << " ";
    }
    cout << endl;
}