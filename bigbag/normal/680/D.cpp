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

const int max_n = 1111111;
const long long inf = 1111111111111111111LL;

pair<int, long long> solve(long long n, int res) {
    if (res == 0) {
        return make_pair(0, 0);
    }
    long long x = 0;
    if (res == -1) {
        res = 0;
        for (int i = 1; ; ++i) {
            long long q = i;
            q *= i;
            q *= i;
            long long q2 = i + 1;
            q2 *= i + 1;
            q2 *= i + 1;
            if (x + q > n) {
                break;
            }
            while (x + q < q2 && x + q <= n) {
                x += q;
                ++res;
            }
        }
    }
    int Q = res;
    //cout << n << " " << res <<  " " << x << "  ";
    x = 0;
    int st;
    for (int i = 1; ; ++i) {
        long long q = i;
        q *= i;
        q *= i;
        long long q2 = i + 1;
        q2 *= i + 1;
        q2 *= i + 1;
        if (x + q > n) {
            break;
        }
        while (x + q < q2 && x + q <= n) {
            if (res == 1) {
                st = i;
                break;
            }
            x += q;
            --res;
        }
    }

    long long mx, W;
    for (int i = st; ; ++i) {
        long long q = i;
        q *= i;
        q *= i;
        long long q2 = i + 1;
        q2 *= i + 1;
        q2 *= i + 1;
        if (x + q > n) {
            break;
        }
        if (x + q < q2) {
            mx = q;
            W = q2 - q;
        }
    }
    //cout << mx << endl;
    //string F;
    //cin >> F;
    pair<int, long long> ans = solve(min(n - mx, W), Q - 1);
    ans.first = Q;
    ans.second += mx;
    return ans;
}

long long n;

void proc(long long x) {
    int res = 0;
    while (x) {
        ++res;
        for (long long i = 2; ; ++i) {
            if (i * i * i > x) {
                --i;
                x -= i * i * i;
                cout << i * i * i << endl;
                break;
            }
        }
    }
    cout << res << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    pair<int, long long> ans = solve(n, -1);
    cout << ans.first << " " << ans.second << endl;
    //proc(ans.second);
    return 0;
}