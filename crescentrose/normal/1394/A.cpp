#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
int n, d, m;
vector<long long> a, b;
int main() {
    scanf("%d %d %d", &n, &d, &m);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        if (x <= m)
            a.push_back(x);
        else
            b.push_back(x);
    }
    sort(a.begin(), a.end(), greater<long long>());
    sort(b.begin(), b.end(), greater<long long>());
    for (int i = 1; i < a.size(); i ++)
        a[i] += a[i - 1];
    for (int i = 1; i < b.size(); i ++)
        b[i] += b[i - 1];
    long long ans = 0;
    for (int i = 0; i <= b.size(); i ++) {
        long long tmp = 0;
        long long v1 = 0;
        if (!i) tmp = 0;
        else {
            tmp = (i - 1) * d + i;
            v1 = b[i - 1];
        }
        if (tmp > n) break;
        if (!a.size()) ans = max(ans, v1);
        else {
            ans = max(ans, v1 + (n == tmp ? 0 : a[min(n - tmp - 1, (long long)a.size() - 1)]));
        }
    }
    printf("%lld\n", ans);
    return 0;
}