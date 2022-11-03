#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;

typedef unsigned long long ll;

const int max_n = 2e5 + 100;

int n, m;
int a[max_n], b[max_n];
set<int> not_full;

void go(int sum, int num) {
    if (num >= n) return;
    if (sum == 0) return;
    b[num] += sum;
    if (b[num] >= a[num]) {
        not_full.erase(num);
        int nx = (*not_full.lower_bound(num));
        go(b[num] - a[num], nx);
        b[num] = a[num];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i <= n; ++i)
        not_full.insert(i);
    for (cin >> m; m; --m) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            go(x, p);
        } else if (tp == 2) {
            int k;
            cin >> k;
            --k;
            cout << b[k] << endl;
        }
    }
    return 0;
}