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

const int max_n = 222222, inf = 1111111111;

int n, a[max_n];
vector<pair<int, int> > ans;
vector<int> v;

bool ok(int poz) {
    if (poz < 0 || poz + 1 >= n) {
        return true;
    }
    if (poz % 2 == 0) {
        if (a[poz] >= a[poz + 1]) {
            return false;
        }
    } else {
        if (a[poz] <= a[poz + 1]) {
            return false;
        }
    }
    return true;
}

bool ok() {
    for (int i = 0; i < v.size(); ++i) {
        int poz = v[i];
        if (!ok(poz)) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (!ok(i)) {
            v.push_back(i);
        }
    }
    if (v.size() > 10) {
        printf("0\n");
        return 0;
    }
    for (int I = 0; I < v.size(); ++I) {
        for (int i = v[I] - 1; i <= v[I] + 1; ++i) {
            if (i < 0 || i >= n) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                swap(a[i], a[j]);
                if (ok()) {
                    if (ok(i - 1) && ok(i) && ok(i + 1) && ok(j - 1) && ok(j) && ok(j + 1)) {
                        int x = min(i, j);
                        int y = max(i, j);
                        ans.push_back(make_pair(x, y));
                    }
                }
                swap(a[i], a[j]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    return 0;
}