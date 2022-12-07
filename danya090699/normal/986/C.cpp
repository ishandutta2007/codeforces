#include <bits/stdc++.h>
using namespace std;
const int sz=(1<<22);
bool ar[sz], us[2][sz];
int n, m, bg;
void dfs(int v, int t)
{
    us[t][v]=1;
    if(t==0)
    {
        if(us[1][bg^v]==0) dfs(bg^v, 1);
    }
    else
    {
        if(ar[v] and us[0][v]==0) dfs(v, 0);
        for(int i=0; i<n; i++)
        {
            if(v&(1<<i))
            {
                int ne=v-(1<<i);
                if(us[1][ne]==0) dfs(ne, 1);
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int an=0;
    cin>>n>>m;
    bg=(1<<n)-1;
    for(int a=0; a<m; a++)
    {
        int x;
        scanf("%d", &x);
        ar[x]=1;
    }
    for(int a=0; a<(1<<n); a++)
    {
        if(ar[a] and us[0][a]==0)
        {
            dfs(a, 0), an++;
        }
    }
    cout<<an;
}