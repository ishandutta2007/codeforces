/**
 *  created: 04/01/2021, 16:43:18
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        long long sum = 0;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] % 2 == 0) {
                sum += a[i];
                v.push_back(-a[i]);
            } else {
                v.push_back(-a[i]);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i += 2) {
            sum += v[i];
        }
        if (sum > 0) {
            puts("Alice");
        } else if (sum < 0) {
            puts("Bob");
        } else {
            puts("Tie");
        }
    }
    return 0;
}