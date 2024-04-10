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

const int max_bit = 20, max_n = 100011, inf = 111111111;

int n, m, a[max_n];
bool x[max_bit][max_n];
set<int> s[max_bit];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long sum = 0;
    for (int bit = 0; bit < max_bit; ++bit) {
        s[bit].insert(0);
        s[bit].insert(n + 1);
        for (int i = 1; i <= n; ++i) {
            x[bit][i] = get_bit(a[i], bit);
            if (x[bit][i] == 0) {
                s[bit].insert(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (x[bit][i] == 1) {
                set<int>::iterator it = s[bit].upper_bound(i);
                sum += ((long long) (*it - i)) * (1 << bit);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int poz, value;
        cin >> poz >> value;
        for (int bit = 0; bit < max_bit; ++bit) {
            if (get_bit(value, bit) != x[bit][poz]) {
                if (get_bit(value, bit) == 1) {
                    set<int>::iterator it = s[bit].find(poz);
                    ++it;
                    long long r = *it;
                    --it;
                    --it;
                    long long l = *it;
                    ++l;
                    --r;
                    if (l < poz) {
                        sum -= (poz - l) * (poz - l + 1) / 2 * (1 << bit);
                    }
                    if (poz < r) {
                        sum -= (r - poz) * (r - poz + 1) / 2 * (1 << bit);
                    }
                    sum += (r - l + 1) * (r - l + 2) / 2 * (1 << bit);
                    s[bit].erase(poz);
                } else {
                    set<int>::iterator it = s[bit].upper_bound(poz);
                    long long r = *it;
                    --it;
                    long long l = *it;
                    ++l;
                    --r;
                    sum = sum + (poz - l) * (poz - l + 1) / 2 * (1 << bit) + (r - poz) * (r - poz + 1) / 2 * (1 << bit) - (r - l + 1) * (r - l + 2) / 2 * (1 << bit);
                    s[bit].insert(poz);
                }
                x[bit][poz] = get_bit(value, bit);
            }
        }
        cout << sum << endl;
    }
    return 0;
}