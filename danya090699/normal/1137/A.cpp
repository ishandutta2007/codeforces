#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    map <int, int> ro[n], co[m];
    int fi[n][m];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            scanf("%d", &fi[a][b]);
            ro[a][fi[a][b]]=0;
            co[b][fi[a][b]]=0;
        }
    }
    for(int a=0; a<n; a++)
    {
        int q=0;
        for(auto it=ro[a].begin(); it!=ro[a].end(); it++) (*it).second=q, q++;
    }
    for(int a=0; a<m; a++)
    {
        int q=0;
        for(auto it=co[a].begin(); it!=co[a].end(); it++) (*it).second=q, q++;
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            int x=fi[a][b];
            int an=max(ro[a][x], co[b][x])+max(ro[a].size()-ro[a][x], co[b].size()-co[b][x]);
            printf("%d ", an);
        }
        printf("\n");

    }
}