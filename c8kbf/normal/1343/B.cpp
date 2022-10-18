#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, tc;

int main() {
    
    scanf("%lld", &tc);
    for(; tc--; ) {

        scanf("%lld", &n);
        if(n&3) puts("NO");
        else {
            puts("YES");
            for(_ i = 2; i <= n; i += 2) printf("%lld ", i);
            for(_ i = 1; i <= n; i += 2) {
                 if(i == n-1) i += (n>>1);
                 printf("%lld ", i);
            }
            putchar(10);
        }
 
    }

    return 0;
}