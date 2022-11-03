#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    int l = -2e9;
    int r = 2e9;
    
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        char tp[10];
        char ans;
        int x;
        scanf("%s %d %c\n", tp, &x, &ans);
        if (strcmp(tp, ">=") == 0) {
            if (ans == 'Y') {
                l = max(l, x);
            } else {
                r = min(r, x - 1);
            }
        } else if (strcmp(tp, "<") == 0) {
            if (ans == 'Y') {
                r = min(r, x - 1);
            } else {
                l = max(l, x);
            }
        } else if (strcmp(tp, ">") == 0) {
            if (ans == 'Y') {
                l = max(l, x + 1);
            } else {
                r = min(r, x);
            }
        } else if (strcmp(tp, "<=") == 0) {
            if (ans == 'Y') {
                r = min(r, x);
            } else {
                l = max(l, x + 1);
            }
        } else {
            assert(false);
        }
    }
    if (l <= r) {
        printf("%d\n", l);
    } else {
        printf("Impossible\n");
    }
    return 0;
}