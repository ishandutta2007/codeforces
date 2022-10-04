#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 100;
int n, a[mx], best = 1e9;

int main()
{
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int x = 0; x < n; ++x) {
        for (int y = x + 1; y < n; ++y) {
            int ans = 0;
            vector<int> e;
            for (int i = 0; i < n; ++i) {
                if (i != x && i != y)
                    e.push_back(a[i]);
            }
            for (int i = 0; i < n / 2 - 1; ++i) {
                ans += e[2*i+1] - e[2*i];
            }
            best = min(best, ans);
        }
    }
    cout << best << endl;
    return 0;
}