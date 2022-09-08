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

const int max_n = 1, inf = 1000111222;

long long p;
int k;

vector<int> solve(long long p, int k) {
    vector<int> res;
    int nxt = 0;
    for (int i = 0; p || nxt; ++i) {
        int nx = 0;
        int o = p % k;
        o += nxt;
        //cout << i << " " << o << " " << nxt << endl;

        if (i % 2 == 0) {
            if (o >= k) {
                o -= k;
                nx = 1;
            } else if (o < 0) {
                o += k;
                nx = -1;
            }
        } else {
            o *= -1;
            if (o >= k) {
                o -= k;
                nx = -1;
            } else if (o < 0) {
                o += k;
                nx = 1;
            }
        }

        nxt = nx;
        res.push_back(o);
        p /= k;
    }
    return res;
}

long long f(const vector<int> &v, int k) {
    long long res = 0, pw = 1;
    for (int i = 0; i < v.size(); ++i) {
        if (i % 2 == 0) {
            res += pw * v[i];
        } else {
            res -= pw * v[i];
        }
        pw *= k;
    }
    return res;
}

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> p >> k;
    auto ans = solve(p, k);
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}