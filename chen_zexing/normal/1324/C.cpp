#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
using namespace std;
char a[200005];
int main() {
    int T;
    cin >> T;
    while (T--) {
        scanf("%s", a);
        int count = 0, ans = 0;
        for (int i = 0; i < strlen(a); i++) {
            count++;
            if (a[i] == 'R') {
                ans = max(ans, count);
                count = 0;
            }
        }
        count++;
        ans = max(ans, count);
        printf("%d\n", ans);
    }
    return 0;
}