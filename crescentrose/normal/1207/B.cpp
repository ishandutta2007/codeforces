#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int a[100][100];
bool bz[100][100];
int n , m;
vector< pair<int, int> > ans;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);
    for (int i = 2; i <= n ; i ++)
        for (int j = 2; j <= m ; j ++)
            if (a[i][j] && a[i - 1][j] && a[i -1][j -1] && a[i][j - 1]){
                bz[i][j] = bz[i - 1][j] = bz[i ][j - 1] = bz[i - 1][j - 1] = 1;
                ans.push_back(make_pair(i - 1,j - 1));
            }
    for (int i = 1; i<=n ; i++)
        for (int j = 1; j <= m ;  j++)
            if (a[i][j] && !bz[i][j]) {
                printf("-1");
                return 0;
            }
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%d %d\n",u.first, u.second);
    return 0;
}