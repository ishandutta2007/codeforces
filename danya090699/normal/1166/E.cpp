#include <bits/stdc++.h>
using namespace std;
const int sz=1e4+10, sz2=55;
int us[sz2][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int m, n;
    cin>>m>>n;
    for(int a=0; a<m; a++)
    {
        int q;
        cin>>q;
        for(int b=0; b<q; b++)
        {
            int x;
            scanf("%d", &x);
            x--, us[a][x]=1;
        }
    }
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<m; b++)
        {
            bool ok=0;
            for(int c=0; c<n; c++)
            {
                if(us[a][c]==1 and us[b][c]==1) ok=1;
            }
            if(ok==0)
            {
                cout<<"impossible";
                return 0;
            }
        }
    }
    cout<<"possible";
}