/*  * In the name of GOD 
    * Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10000002;
int s[N], ans[N];

int32_t main() {
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            if (s[j] >= N)
                continue;
            s[j] += i;
        }
    }
    for (int i = 1; i < N; i++) {
        if (s[i] + 1 < 0 || s[i] + 1 >= N)
            continue;
        if (ans[s[i] + 1] == 0) { 
            ans[s[i] + 1] = i;
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        int a = ans[x];
        if (a == 0) {
            printf("-1 ");
        } else {
            printf("%d ", a);
        }
    }
}