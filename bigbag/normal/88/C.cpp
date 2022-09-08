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

const int max_n = 1111111, inf = 1111111111;

long long gcd(long long a, long long b) {
    a = abs(a);
    b = abs(b);
    while (a != 0 && b != 0) {
        long long k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

long long a[5];

struct state {
    long long t, f;
    state(long long t, int f) : t(t), f(f) {
    }
    bool operator < (const state &q) const {
        return t < q.t;
    }
};

vector<state> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a[0] >> a[1];
    long long g = a[0] * a[1] / gcd(a[0], a[1]);
    //cout << g << endl;
    for (long long i = a[0]; i < g; i += a[0]) {
        v.push_back(state(i, 0));
    }
    for (long long i = a[1]; i < g; i += a[1]) {
        v.push_back(state(i, 1));
    }
    if (a[0] > a[1]) {
        v.push_back(state(g, 0));
    } else {
        v.push_back(state(g, 1));
    }
    v.push_back(state(0, -1));
    sort(v.begin(), v.end());
    long long cnt[5];
    cnt[0] = cnt[1] = 0;
    for (int i = 1; i < v.size(); ++i) {
        //cout << v[i].t << ' ' << v[i].f << endl;
        cnt[v[i].f] += v[i].t - v[i - 1].t;
    }
    //cout << cnt[0] << endl << cnt[1] << endl;
    if (cnt[0] == cnt[1]) {
        cout << "Equal" << endl;
    }
    if (cnt[0] > cnt[1]) {
        cout << "Dasha" << endl;
    }
    if (cnt[0] < cnt[1]) {
        cout << "Masha" << endl;
    }
    return 0;
}