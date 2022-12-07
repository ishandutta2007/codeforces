//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=110;
int ar[11][sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, z;
    cin>>n>>q>>z;
    z++;
    for(int a=0; a<z; a++) for(int b=0; b<sz; b++) for(int c=0; c<sz; c++) ar[a][b][c]=0;
    for(int a=0; a<n; a++)
    {
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        for(int b=0; b<z; b++)
        {
            ar[b][x][y]+=s, s=(s+1)%z;
        }
    }
    for(int a=0; a<z; a++)
    {
        for(int b=1; b<sz; b++)
        {
            for(int c=1; c<sz; c++)
            {
                ar[a][b][c]+=ar[a][b][c-1]+ar[a][b-1][c];
                ar[a][b][c]-=ar[a][b-1][c-1];
            }
        }
    }
    for(int a=0; a<q; a++)
    {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        t=t%z;
        int re=ar[t][x2][y2]-ar[t][x2][y1-1]-ar[t][x1-1][y2]+ar[t][x1-1][y1-1];
        printf("%d\n", re);
    }
}