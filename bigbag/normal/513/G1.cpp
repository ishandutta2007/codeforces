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

const int max_n = 7, inf = 1111111111;

int n, k, a[max_n];
long long ans, cnt;

void rec(int poz) {
    if (poz == k) {
        ++cnt;
        int cnt2 = 0;
        /*for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }*/
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) ++cnt2;
            }
        }
        //cout << " + " << cnt2 << endl;
        ans += cnt2;
        return;
    }
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            reverse(a + l, a + r + 1);
            rec(poz + 1);
            reverse(a + l, a + r + 1);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    rec(0);
    printf("%.10lf\n", 1.0 * ans / cnt);
    //cout << ans << " " << cnt;
    return 0;
}