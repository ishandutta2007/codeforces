#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5;
int n, T;
int a[N];
vector<pair<int , int> > d, dd;
vector<pair<pair<int, int>, int> > ans;
void work(pair<pair<int, int>, int> v) {
    ans.push_back(v);
    a[v.first.first] -= v.second * v.first.first;
    a[v.first.second] += v.second * v.first.first;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        int all = 0;
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]), all += a[i];
        if (all % n) {
            puts("-1");
            continue;
        }
        all /= n;
        ans.clear();
        bool sig = 1;
        d.clear();
        int cnt = 0;
        for (int i = 2; i <= n && cnt < 3; i ++) {
            if (a[i] / i) {
                ++cnt;
                work({{i, 1}, a[i] / i});
            }
        }
        for (int i = 2; i <= n; i ++)
        {
            if (a[i] % i) {
                if (i - a[i] % i > a[1]) {
                    sig = 0;
                    break;
                }
                work({{1, i}, i - a[i] % i});
            }
            work({{i, 1}, a[i] / i});
        }
        if (!sig) {
            puts("-1");
            continue;
        }

        for (int i = 2; i <= n;i ++)
            work({{1, i}, all});
        for (int i = 2; i <= n;i ++)
            if (a[i] != all)
                work({{1, i}, all - a[i]});
        printf("%d\n", (int)ans.size());
        for (auto u:ans)
            printf("%d %d %d\n", u.first.first, u.first.second, u.second);
    }
    return 0;
}