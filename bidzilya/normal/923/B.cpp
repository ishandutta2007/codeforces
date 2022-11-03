#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

int n;
vector<int> v;
vector<int> t;

vector<long long> st;

long long GetT(int l, int r) {
    return l == 0 ? st[r] : st[r] - st[l - 1];
}

vector<int> mul;
vector<long long> sum;

void Solve() {
    st.resize(n);
    for (int i = 0; i < n; ++i) {
        st[i] = t[i];
        if (i > 0) {
            st[i] += st[i - 1];
        }
    }
    mul.assign(n, 0);
    sum.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        int bl = i;
        int br = n - 1;
        int ba = n;
        while (bl <= br) {
            int bm = (bl + br) >> 1;

            long long ct = GetT(i, bm);
            if (ct > v[i]) {
                ba = bm;
                br = bm - 1;
            } else {
                bl = bm + 1;
            }
        }
        ++mul[i];
        if (ba != n) {
            --mul[ba];

            long long ct = GetT(i, ba) - t[ba];
            long long cv = v[i] - ct;
            sum[ba] += cv;
        }
    }
    long long cmul = 0;
    for (int i = 0; i < n; ++i) {
        cmul += mul[i];
        cout << cmul * t[i] + sum[i] << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}