#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int max_n = 1e4;

int x, k;
int us[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    
    while (scanf("%d%d", &x, &k) != EOF) {
        for (int i = 0; i < max_n; ++i)
            us[i] = 0;
        for (int i = 0; i < k; ++i) {
            int tp;
            scanf("%d", &tp);
            if (tp == 1) {
                int n1, n2;
                scanf("%d%d", &n1, &n2);
                us[n1] = us[n2] = 1;
            } else if (tp == 2) {
                int n;
                scanf("%d", &n);
                us[n] = 1;
            }
        }
        us[x] = 1;
        int cnt = 0;
        for (int i = 1; i < x; ++i)
            cnt += (!us[i]);
        int mx = cnt;
        int mn = cnt;
        for (int i = 1; i < x; )
            if (!us[i] && !us[i + 1]) {
                --mn;
                i += 2;
            } else {
                ++i;
            }
        printf("%d %d\n", mn, mx);
    }
    
    return 0;
}