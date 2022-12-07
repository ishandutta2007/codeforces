#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, ok=1;
    cin>>n>>m;
    int ma[2][n][m];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++) scanf("%d", &ma[i][a][b]);
        }
    }
    for(int a=0; a<n+m-1; a++)
    {
        vector <int> ve[2];
        for(int b=0; b<n; b++)
        {
            int c=a-b;
            if(c>=0 and c<m) ve[0].push_back(ma[0][b][c]), ve[1].push_back(ma[1][b][c]);
        }
        sort(ve[0].begin(), ve[0].end());
        sort(ve[1].begin(), ve[1].end());
        for(int b=0; b<ve[0].size(); b++) if(ve[0][b]!=ve[1][b]) ok=0;
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}