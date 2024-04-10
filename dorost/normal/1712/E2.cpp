/*  * In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll; 
typedef long double ld; 
#define F first
#define S second
const int N = 2 * 2 * 1069 * 100;
vector <int> divs[N];
int fen[2][N]; // 0 -> 1,2 | 1 -> 2-good
vector <pair <int, pair <int, int>>> add[N]; // l, cnt-good, cnt-bad
vector <pair <int, int>> q[N]; // l, id
ll ans[N];

void upd (int id, int i, int x) {
    for (; i < N; i += (i & -i))
        fen[id][i] += x;
}

int get (int id, int r) {
    int ans = 0;
    for (; r; r ^= (r & -r))
        ans += fen[id][r];
    return ans;
}

ll C2 (int x) {
    return ((ll)x * (ll)(x - 1)) / 2LL;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    for (int i = 1; i <= 200000; i++) 
        for (int j = i * 2; j <= 400000; j += i)  
            divs[j].push_back(i);
    for (int k = 1; k <= 200000; k++) {
        for (int in = 0; in < (int)divs[k * 2].size(); in++) {
            int wef = 0, wef2 = 0;
            int i = divs[k * 2][in];
            int in2 = upper_bound(divs[k * 2].begin(), divs[k * 2].end(), k - i) - divs[k * 2].begin() - 1;
            wef2 += max(in2 - in, 0); 
            int in3 = lower_bound(divs[k * 2].begin(), divs[k * 2].end(), k) - divs[k * 2].begin() - 1;
            wef += max(in3 - in, 0);
            if (k % i == 0) {
                int in4 = lower_bound(divs[k].begin(), divs[k].end(), i) - divs[k].begin();
                int in5 = lower_bound(divs[k].begin(), divs[k].end(), k) - divs[k].begin() - 1;
                wef += max(in5 - in4, 0); 
            }
            add[k].push_back(make_pair(i, make_pair(wef2, wef)));
        }
    }   
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        q[r].push_back(make_pair(l, i));
    }   
    for (int r = 1; r <= 200000; r++) {
        for (pair <int, pair <int, int>> p : add[r]) {
            upd (0, p.F, p.S.S);
            upd (1, p.F, p.S.F);
        }
        for (pair <int, int> p : q[r]) {
            int l = p.F;
            int bad = get (0, r) - get(0, l - 1); 
            int good = get (1, r) - get(1, l - 1); 
            ans[p.S] = ((ll)(r - l + 1) * (ll)(r - l) * (ll)(r - l - 1)) / 6LL - bad + good;
        }
    }   
    for (int i = 0; i < t; i++) {
        cout << ans[i] << ' ';
    }   
}