#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, fo=0;
    cin>>n>>m;
    bool us[n][2];
    for(int a=0; a<m; a++)
    {
        int q, fo2=0;
        cin>>q;
        for(int b=0; b<n; b++)
        {
            us[b][0]=0, us[b][1]=0;
        }
        for(int b=0; b<q; b++)
        {
            int x;
            cin>>x;
            if(x<0)
            {
                x=-x;
                x--;
                us[x][1]=1;
            }
            else
            {
                x--;
                us[x][0]=1;
            }
        }
        for(int b=0; b<n; b++)
        {
            if(us[b][0]==1 and us[b][1]==1) fo2=1;
        }
        if(fo2==0)
        {
            fo=1;
            cout<<"YES";
            break;
        }
    }
    if(fo==0) cout<<"NO";
}