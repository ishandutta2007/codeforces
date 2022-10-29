#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mk make_pair
const int N = 100005;
const int inf = (int)2e9;
int a[10], b[N], n, t[N][7], tot = 0, vis[N];
pii A[N * 7];
int _abs(int x) { return x < 0 ? -x : x; }
 
void solve()
{
    for (int i = 1; i <= 6; i++)
        scanf("%d", &a[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            t[i][j] = b[i] - a[j];
            A[++tot] = mk(t[i][j], i);
        }
    }
    sort(A + 1, A + n * 6 + 1);
    int cnt = 0, ans = inf;
    for (int i = 1, j = 1; i <= n * 6; i++)
    {
        if (!vis[A[i].second])
        {
            cnt++;
        }
        vis[A[i].second]++;
        int flag = 0;
        while (cnt == n)
        {
            flag = 1;
            if (vis[A[j].second] == 1)
                break;
            vis[A[j].second]--;
            j++;
        }
        if (flag)
            ans = min(ans, A[i].first - A[j].first);
    }
    cout << ans << endl;
}
 
int main()
{
    int T = 1; //scanf("%d",&T);
    while (T--)
    {
        solve();
    }
    return 0;
}