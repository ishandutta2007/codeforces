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

const int max_n = 111111, inf = 111111111;

int n, k, a[max_n];
set<int> s;
map<int, int> cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i < k) {
            if (cnt.count(a[i])) {
                if (cnt[a[i]] == 1) {
                    s.erase(a[i]);
                }
                ++cnt[a[i]];
            } else {
                cnt[a[i]] = 1;
                s.insert(a[i]);
            }
        }
    }
    for (int i = 0; i < n - k + 1; ++i) {
        if (s.size() == 0) {
            cout << "Nothing" << endl;
        } else {
            cout << *s.rbegin() << endl;
        }
        if (cnt[a[i]] == 1) {
            cnt[a[i]] = 0;
            s.erase(a[i]);
        } else if (cnt[a[i]] == 2) {
            cnt[a[i]] = 1;
            s.insert(a[i]);
        } else {
            --cnt[a[i]];
        }
        int poz = i + k;
        if (!cnt.count(a[poz]) || cnt[a[poz]] == 0) {
            cnt[a[poz]] = 1;
            s.insert(a[poz]);
        } else if (cnt[a[poz]] == 1) {
            cnt[a[poz]] = 2;
            s.erase(a[poz]);
        } else {
            ++cnt[a[poz]];
        }
    }
    return 0;
}