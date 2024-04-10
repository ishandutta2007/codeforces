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

const int max_p = 2222222;

int used[max_p];

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            if ((long long) i * i < (long long) max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}

const int max_n = 2222222, inf = 1111111111;

int n, ans, a[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    ans = max(1, cnt[1]);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] != a[j] && used[a[i] + a[j]] == 0) {
                ans = max(ans, 2);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != 1 && used[a[i] + 1] == 0) {
            ans = max(ans, cnt[1] + 1);
        }
    }
    cout << ans << endl;
    if (ans == 1) {
        cout << a[0] << endl;
    } else if (ans == cnt[1]) {
        for (int i = 0; i < cnt[1]; ++i) {
            cout << "1 ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (ans == 2 && a[i] != a[j] && used[a[i] + a[j]] == 0) {
                    cout << a[i] << " " << a[j] << endl;
                    return 0;
                }
            }
        }
        for (int i = 0; i < cnt[1]; ++i) {
            cout << "1 ";
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != 1 && used[a[i] + 1] == 0) {
                cout << a[i];
                break;
            }
        }
        cout << endl;
    }
    return 0;
}