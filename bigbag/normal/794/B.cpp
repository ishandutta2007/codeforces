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

const int max_n = 1, inf = 1011111111;

int n, h;

long double get(long double r) {
    long double x = (h - r) / h;
    //cout << "#" << x << endl;
    return (x + 1) * r / 2;
}

long double get(long double l, long double r) {
    return get(r) - get(l);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &h);
    long double s = h;
    s /= 2;
    s /= n;
    long double pos = 0;
    vector<double> ans;
    for (int i = 1; i < n; ++i) {
        long double l = pos, r = h;
        for (int j = 0; j < 111; ++j) {
            long double mid = (l + r) / 2;
            if (get(pos, mid) >= s) {
                r = mid;
            } else {
                l = mid;
            }
        }
        pos = l;
        ans.push_back(h - pos);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%.10f ", ans[i]);
    }
    printf("\n");
    return 0;
}