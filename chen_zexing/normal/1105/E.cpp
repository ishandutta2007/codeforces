
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll mod = 1000000007;
const int maxn = 50;
#define INF 0xffffff
 
int mm[maxn][maxn];
map<string,int> name;
int n, m, Ans;
int Set[60], dp[maxn];
 
bool judge(int en, int point)
 {
     int i;
     for (i = 1; i < en; i++)
     {
         if (!mm[Set[i]][point]) return false;
     }
     return true;
}
 
void dfs(int depth, int now)
{
    if (depth + m - now + 1 <= Ans || depth + dp[now] <= Ans) return;
    for (int i = now; i <= m; i++)
    {
        if (judge(depth + 1, i))
        {
            Set[depth + 1] = i;
            dfs(depth + 1, i + 1);
        }
    }
    if (depth > Ans) Ans = depth;
}
 
 
int main()
{
    scanf("%d%d",&n,&m);
    int tot = 1;
    memset(mm,0,sizeof(mm));
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        if(k==1)
        {
            res.clear();
        }
        else
        {
            char str[maxn];
            scanf("%s",str);
            if(!name.count(str))
            {
                name[str] = tot++;
            }
            int f = 1;
            for(int j=0;j<res.size();j++)
            {
                int tmp = res[j];
                if(tmp==name[str])
                {
                    f= 0;
                    break;
                }
                mm[name[str]][tmp] = mm[tmp][name[str]] = 1;
            }
            if(f)
                res.push_back(name[str]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mm[i][j]^=1;
        }
    }
    Ans = 0;
    dp[m] = 1;
    for(int i=m-1;i>=1;i--)
    {
        Set[1] = i;
        dfs(1,1+i);
        dp[i] = Ans;
    }
    printf("%d\n",dp[1]);
}