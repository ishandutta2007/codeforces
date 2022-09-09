#include<cstdio>
#include<algorithm>
#define CNT(X) cnt[MAX_N + (X)]
using namespace std;
const int MAX_N = 200000;
int cnt[MAX_N * 2 + 1];
void solve() {
    int n;
    scanf("%d", &n);
    long long an = 0;
    for(int i = -n; i <= n; i++) CNT(i) = 0;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        an += CNT(x - i);
        CNT(x - i)++;
    }
    printf("%lld\n", an);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}