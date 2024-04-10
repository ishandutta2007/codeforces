//NOT MY PROGRAM!!!
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int> > ans;
char mat[1010][15][15]; int h, w, n, co;
int from[1010], dist[1010];
bool vis[1010];
int diff(int a, int b)
{
    int cnt = 0;
    for(int i = 0; i < h; i ++)
        for(int j = 0; j < w; j ++)
            cnt += mat[a][i][j] != mat[b][i][j];
    return cnt;
}
int prim()
{
    for(int i = 1; i <= n; i ++)
        dist[i] = h * w;
    int tot = 0;
    for(int i = 1; i <= n; i ++)
    {
        int cur = 0, dd = 0x3f3f3f3f;
        for(int j = 1; j <= n; j ++){
            if(!vis[j] && dist[j] < dd)
            {
                dd = dist[j];
                cur = j;
            }
    }
        tot += dd;
        vis[cur] = true;
        ans.push_back(make_pair(cur, from[cur]));
        for(int j = 1; j <= n; j ++)
        {
            if(vis[j])
                continue;
            int dis = diff(cur, j) * co;
            if(dis < dist[j])
            {
                dist[j] = dis;
                from[j] = cur;
            }
        }
    }
    return tot;
}
int main()
{
    scanf("%d%d%d%d", &h, &w, &n, &co);
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j < h; j ++)
            scanf("%s", mat[i][j]);
    printf("%d\n", prim());
    int sn = (int)ans.size();
    for(int i = 0; i < sn; i ++)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;

}