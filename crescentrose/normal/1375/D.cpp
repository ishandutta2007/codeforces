#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1e4;
int sum[N];
int n;
int m;
int a[N];
vector<int> ans;
int getxor(){
    int x = 0;
    while (sum[x])
        x++;
    return x;
}
bool check() {
    for (int i = 1; i <= n; i ++)
        if (a[i] != i - 1) return 0;
    return 1;
}
int main() {
    scanf("%d", &m);
    while (m --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]), sum[i] = 0;
        sum[0] = 0;
        for (int i = 1; i <= n; i ++)
            sum[a[i]] ++;
        ans.clear();
        while (!check()) {
            int x = getxor();
            if (x != n) {
                ans.push_back(x + 1);
                sum[a[x + 1]] --;
                sum[x] ++;
                a[x + 1] = x;
            } else {
                for (int i = 1; i <= n; i++)
                    if (a[i] != i - 1 && a[i] != x) {
                        ans.push_back(i);
                        sum[a[i]]--;
                        a[i] = x;
                        sum[x]++;
                        break;
                    }
            }
        }
        printf("%d\n", (int)ans.size());
        for (auto u:ans)
            printf("%d ", u);
        puts("");
    }
    return 0;
}