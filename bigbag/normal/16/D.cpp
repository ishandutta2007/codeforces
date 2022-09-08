#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

int n, ans, a[max_n];
char s[222];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        gets(s);
        int h = (s[1] - '0') * 10 + s[2] - '0', m = (s[4] - '0') * 10 + s[5] - '0';
        a[i] = h * 60 + m;
        if (h == 12) a[i] -= 720;
        if (s[7] == 'p') {
            a[i] += 720;
        }
    }
    ans = 1;
    int i = 0;
    while (i < n) {
        int cnt = 1;
        while (i + 1 < n && a[i] == a[i + 1] && cnt < 10) {
            i++;
            cnt++;
        }
        if (cnt == 10 && i + 1 < n && a[i] == a[i + 1]) {
            ans++;
        } else {
            if (i + 1 < n && a[i] > a[i + 1]) {
                ans++;
            }
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}