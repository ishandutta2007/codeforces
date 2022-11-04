#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

int n, k, ans = 2e9;

int main() {
    scanf("%d %d", &n, &k);
    fo(x, 1, k - 1) {
        if(n % x == 0) {
            ans = min(ans, x + (n / x) * k);
        }
    }
    printf("%d", ans);
}