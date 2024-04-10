#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

const int max_n = 2e5 + 100;

int n, k;
int h[max_n];

int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    int ans = 0;
    int pos = 0;
    for (int i = 0; i < k; ++i)
        ans += h[i];
    int cans = ans;
    for (int i = k; i < n; ++i) {
        cans += h[i];
        cans -= h[i - k];
        if (cans < ans) {
            ans = cans;
            pos = i - k + 1;
        }
    }
    cout << pos + 1 << endl;
    return 0;
}