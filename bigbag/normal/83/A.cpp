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

const int max_n = 111111, inf = 1111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        long long cnt = 0;
        while (j < n && a[i] == a[j]) {
            ++j;
            ++cnt;
        }
        ans += (cnt * (cnt + 1)) / 2;
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}