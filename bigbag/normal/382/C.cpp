#include <map>
#include <set>
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

const int max_n = 111111, inf = 111111111;

int n, a[max_n];
set<int> sss;
map<int, int> mmm;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (n == 1) {
        cout << "-1" << endl;
        return 0;
    }
    int d = a[1] - a[0], f = 0, poz = 0;
    sss.insert(d);
    mmm[d]++;
    for (int i = 2; i < n; ++i) {
        mmm[a[i] - a[i - 1]]++;
        sss.insert(a[i] - a[i - 1]);
        if (a[i] - a[i - 1] != d) {
            ++f;
            poz = i;
        }
    }
    if (f == 0) {
        if (d == 0) {
            cout << 1 << endl << a[0];
            return 0;
        }
        vector <int> ans;
        ans.push_back(a[0] - d);
        ans.push_back(a[n - 1] + d);
        if (n == 2 && (a[0] + a[1]) % 2 == 0) {
            ans.push_back((a[0] + a[1]) / 2);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i =  0; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
        }
        return 0;
    }
    if (sss.size() == 2) {
        int x, y;
        x = *sss.begin();
        sss.erase(x);
        y = *sss.begin();
        if (mmm[x] == 1) {
            for (int i = 1; i < n; ++i) {
                if (a[i] - a[i - 1] == x) {
                    int q = (a[i] + a[i - 1]) / 2;
                    if (a[i] - q == y && q - a[i - 1] == y) {
                        cout << 1 << endl << q;
                        return 0;
                    }
                }
            }
        }
        if (mmm[y] == 1) {
            for (int i = 1; i < n; ++i) {
                if (a[i] - a[i - 1] == y) {
                    int q = (a[i] + a[i - 1]) / 2;
                    if (a[i] - q == x && q - a[i - 1] == x) {
                        cout << 1 << endl << q;
                        return 0;
                    }
                }
            }
        }
        cout << 0 << endl;

    } else {
        cout << 0 << endl;
    }
    return 0;
}