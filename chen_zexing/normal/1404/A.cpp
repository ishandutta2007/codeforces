#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
char s[300005];
int a[300005];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k, f = 1, cnt = 0;
        cin >> n >> k;
        scanf("%s", s + 1);
        for (int i = 0; i < k; i++) a[i] = 2;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '?') continue;
            if (a[i % k] == 2) a[i % k] = s[i] - '0';
            else if (a[i % k] != s[i] - '0') {
                f = 0;
                break;
            }
        }
        for (int i = 0; i < k; i++)
            if (a[i] == 0)
                cnt++;
        if (cnt > k / 2) f = 0;
        cnt = 0;
        for (int i = 0; i < k; i++)
            if (a[i] == 1)
                cnt++;
        if (cnt > k / 2) f = 0;
        if (f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}