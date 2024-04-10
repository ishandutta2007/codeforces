#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

ll mach(ll n, ll k) {
    if (k == 1) return n*(n+1)/2;
    ll sum = 0;
    for (ll b = 1, l=1; n; b *= k, l++) {
        ll amt = min(b, n);
        n -= amt;
        sum += l*amt;
    }
    return sum;
}

vector<int> ch;
vector<int> par;
vector<int> lvl;
vector<vector<int>> at;
int max_lvl;

void build(int n, int k) {
    ch = vector<int>(n+1, 0);
    par = vector<int>(n+1, 0);
    lvl = vector<int>(n+1, 0);
    at = vector<vector<int>>(n+1);

    at[1].push_back(1);
    lvl[1] = 1;
    int x = 1, y = 0;
    for (int i=2; i<=n; ++i) {
        if (ch[at[x][y]] >= k) {
            ++y;
            if (y >= at[x].size()) {
                ++x;
                y = 0;
            }
        }
        int u = at[x][y];
        ++ch[u];
        lvl[i] = x+1;
        at[x+1].push_back(i);
        par[i] = u;
        //cerr << " parent of " << i << " is  " << u << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, s;
    cin >> n >> s;
    if (s > mach(n, 1) || s < mach(n, n-1)) {
        cout << "No" << endl;
        return 0;
    }
    ll bc = 1;
    for (; bc < n; ++ bc) {
        if (mach(n, bc) < s) {
            bc--;
            break;
        }
    }
    
    build(n, bc);
    int top = 1;

    ll cur = mach(n, bc);
    for (int i = n; cur > s; --i) {
        while (at[top].size() == 0) {
            ++top;
        }
        ll red = min(cur-s, (ll) lvl[i]-top-1);
        int h = lvl[i]-red-1;
        int p = at[h].back();
        if (++ch[p] > bc) {
            at[h].pop_back();
        }
        //cerr << "Move " << i << " from child of " << par[i] << " to child of " << p << " and lose " << red << endl;
        ch[par[i]]--;
        par[i] = p;
        lvl[i] = h+1;
        at[h+1].push_back(i);
        cur -= red;
    }

    cout << "Yes\n";
    for(int i=2; i<=n; ++i) {
        cout << par[i] << " ";
    }
    cout << endl;
    
    return 0;
}