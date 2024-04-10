#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 5555, inf = 111111111;

struct xxx {
    int w, h, ind;
    bool operator < (xxx a) {
        return w < a.w || w == a.w && h < a.h;
    }
};

bool cmp(xxx a, xxx b) {
    return a < b;
}

int n, w, h, f, kol, poz, ans[max_n], from[max_n];
xxx a[max_n];
vector <int> ans1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> w >> h;
    f = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].w >> a[i].h;
        a[i].ind = i + 1;
    }
    sort(a, a + n, cmp);
    kol = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].w <= w || a[i].h <= h) {
            ans[i] = 0;
        }
        else {
            ans[i] = 1;
            from[i] = -1;
            for (int j = 0; j < i; ++j) {
                if (a[j].w < a[i].w && a[j].h < a[i].h && ans[j] + 1 > ans[i]) {
                    ans[i] = ans[j] + 1;
                    from[i] = j;
                }
            }
        }
        if (kol < ans[i]) {
            kol = ans[i];
            poz = i;
        }
    }
    if (kol == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << kol << endl;
    while (poz != -1) {
        ans1.push_back(a[poz].ind);
        poz = from[poz];
    }
    for (int i = ans1.size() - 1; i >= 0; i--) {
        cout << ans1[i] << ' ';
    }
    return 0;
}