#include <bits/stdc++.h>
using namespace std;
const int sz=110;
int q[sz], dp[sz][sz*sz], dp2[sz][sz*sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, dif=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        q[x]++;
    }
    dp[0][0]=1;
    for(int a=0; a<sz; a++)
    {
        if(q[a]) dif++;
        for(int b=0; b<=n; b++)
        {
            for(int c=0; c<sz*n; c++)
            {
                if(dp[b][c])
                {
                    for(int d=0; d<=q[a]; d++) dp2[b+d][c+a*d]=min(dp2[b+d][c+a*d]+dp[b][c], 2);
                }
            }
        }
        for(int b=0; b<=n; b++)
        {
            for(int c=0; c<sz*n; c++) dp[b][c]=dp2[b][c], dp2[b][c]=0;
        }
    }
    int an=0;
    if(dif==2) an=n;
    for(int a=0; a<sz; a++)
    {
        for(int b=1; b<=q[a]; b++) if(dp[b][b*a]==1) an=max(an, b);
    }
    cout<<an;
}