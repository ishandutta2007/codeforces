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

long long h, n;

long long get_ans(long long h, long long n, int f) {
    if (h == 0) {
        return 1;
    }
    long long cnt = (1LL << h) / 2;
    //cout <<cnt << "   " << h << " " << n << " " << f << endl;
    if (f == 0) {
        if (n <= cnt) {
            return get_ans(h - 1, n, 1) + 1;
        }
        return get_ans(h - 1, n - cnt, 0) + cnt * 2;
    } else {
        if (n > cnt) {
            return get_ans(h - 1, n - cnt, 0) + 1;
        }
        return get_ans(h - 1, n, 1) + cnt * 2;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> h >> n;
    cout << get_ans(h, n, 0) - 1 << endl;
    return 0;
}