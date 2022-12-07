#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, inf=1e9, an=1e9;
    cin>>n;
    string ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    m=ar[0].size();
    for(int a=0; a<n; a++)
    {
        int cu=0;
        for(int b=0; b<n; b++)
        {
            bool po=0;
            for(int c=0; c<m; c++)
            {
                if(ar[a]==ar[b].substr(c, m-c)+ar[b].substr(0, c))
                {
                    cu+=c, po=1;
                    break;
                }
            }
            if(po==0)
            {
                cu=inf;
                break;
            }
        }
        an=min(an, cu);
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}