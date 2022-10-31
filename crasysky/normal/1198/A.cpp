#include <algorithm>
#include <iostream>
#define mp make_pair
#define fi first
#define se second
#define maxn 1000006
using namespace std;
int a[maxn];
pair <int, int> b[maxn];
int s1[maxn], s2[maxn];
int fpw(int x, int y){
    int ans = 1;
    for (int i = 1; i <= y; i <<= 1, x *= x)
        if (y & i)
            ans *= x;
    return ans;
}
int main(){
    int n, I;
    cin >> n >> I;
    int len = fpw(2, min(30, 8 * I / n));
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int m = 0;
    for (int i = 1; i <= n; ++ i)
        if (i == 1 || a[i] != a[i - 1])
            b[++ m] = mp(a[i], 1);
        else
            ++ b[m].se;
    for (int i = 1; i <= m; ++ i)
        s1[i] = s1[i - 1] + b[i].se;
    for (int i = m; i; -- i)
        s2[i] = s2[i + 1] + b[i].se;
    int ans = n;
    for (int i = 1; i <= m; ++ i)
        ans = min(ans, s1[i - 1] + s2[min(i + len, m + 1)]);
    cout << ans << endl;
}