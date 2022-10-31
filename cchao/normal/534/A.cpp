#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)

int main() {
    int n; ri(n);
    if(n == 2) puts("1\n1");
    else if(n == 1) puts("1\n1");
    else if(n == 3) puts("2\n1 3");
    else if(n == 4) puts("4\n3 1 4 2");
    else {
        printf("%d\n", n);
        for(int i = 1; i <= n; i += 2) printf("%d ", i);
        for(int i = 2; i <= n; i += 2) printf("%d ", i);
        puts("");
    }
    return 0;
}