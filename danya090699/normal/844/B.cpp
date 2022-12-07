//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q=0;
    cin>>n>>m;
    bool ar[n][m];
    for(int a=0; a<n; a++)
    {
        int q1=0;
        for(int b=0; b<m; b++)
        {
            cin>>ar[a][b];
            if(ar[a][b]) q1++;
        }
        q+=(1ll<<q1)-1;
        q+=(1ll<<(m-q1))-1;
    }
    for(int a=0; a<m; a++)
    {
        int q1=0;
        for(int b=0; b<n; b++) if(ar[b][a]) q1++;
        q+=(1ll<<q1)-1;
        q+=(1ll<<(n-q1))-1;
    }
    q-=n*m;
    cout<<q;
}