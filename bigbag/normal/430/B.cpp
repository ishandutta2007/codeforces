#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1111111111;

int n, k, x, a[max_n];
vector<int> v;

int go(int p) {
    int q = v.size(), res = 0;
    for (int i = 0; i < q; ++i) {
        vector<int> v1;
        for (int j = 0; j < v.size(); ) {
            int poz = j, cnt = 0;
            while (poz < v.size() && v[j] == v[poz]) {
                ++cnt;
                ++poz;
            }
            if (cnt < 3) {
                for (int w = j; w < poz; ++w) {
                    v1.push_back(v[w]);
                }
            } else {
                res += cnt;
                if (j <= p && p < poz) --res;
            }
            j = poz;
        }
        v = v1;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        v.clear();
        for (int j = 0; j < i; ++j) {
            v.push_back(a[j]);
        }
        v.push_back(x);
        for (int j = i; j < n; ++j) {
            v.push_back(a[j]);
        }
        ans = max(ans, go(i));
    }
    cout << ans << endl;
    return 0;
}