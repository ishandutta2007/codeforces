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

const int max_n = 11, inf = 1000000000;

int pl, pr, vl, vr, k, L, R;
long long ans;
vector<int> v;

void gen(int x, int cnt) {
    v.push_back(x);
    if (cnt == 9) {
        return;
    }
    gen(x * 10 + 4, cnt + 1);
    gen(x * 10 + 7, cnt + 1);
}

int cnt(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (l2 > r1) {
        return 0;
    }
    return min(r1, r2) - l2 + 1;
}

void proc(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (l2 > r1) {
        return;
    }
    L = l2;
    R = min(r1, r2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> pl >> pr >> vl >> vr >> k;
    proc(pl, pr, vl, vr);
    gen(0, 0);
    v.push_back(inf + 10);
    sort(v.begin(), v.end());
    for (int i = 1; i + k < v.size(); ++i) {
        int l1 = v[i - 1] + 1;
        int r1 = v[i];
        int l2 = v[i + k - 1];
        int r2 = v[i + k] - 1;
        //if (i + k + 1 == v.size()) cout << i << ": " << v[i] << "  " << l1 << " " << r1 << "  " << l2 << " " << r2 << endl;
        long long c1 = cnt(l1, r1, pl, pr);
        long long c2 = cnt(l2, r2, vl, vr);
        ans += c1 * c2;
        c1 = cnt(l2, r2, pl, pr);
        c2 = cnt(l1, r1, vl, vr);
        ans += c1 * c2;
        if (k == 1 && L <= r1 && r1 <= R) ans -= 1;
    }
    printf("%.10f\n", 1.0 * ans / (pr - pl + 1) / (vr - vl + 1));
    return 0;
}