#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[2][n], pref[2][2][n], prefsu[2][n];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++) scanf("%lld", &ar[i][a]);
    }
    for(int i=0; i<2; i++)
    {
        pref[i][0][n-1]=0, pref[i][1][n-1]=0, prefsu[i][n-1]=ar[i][n-1];
        for(int a=n-2; a>=0; a--)
        {
            pref[i][0][a]=pref[i][0][a+1]+prefsu[i][a+1];
            pref[i][1][a]=pref[i][1][a+1]+ar[i][a]*(n-1-a);
            prefsu[i][a]=prefsu[i][a+1]+ar[i][a];
        }
    }
    int be=0, cu=0;
    for(int a=0; a<n; a++)
    {
        if(a&1)
        {
            be=max(be, cu+pref[1][0][a]+prefsu[1][a]*(a*2)+pref[0][1][a]+prefsu[0][a]*(a*2+(n-a)));

            cu+=ar[0][a]*(a*2+1)+ar[1][a]*(a*2);
        }
        else
        {
            be=max(be, cu+pref[0][0][a]+prefsu[0][a]*(a*2)+pref[1][1][a]+prefsu[1][a]*(a*2+(n-a)));

            cu+=ar[0][a]*(a*2)+ar[1][a]*(a*2+1);
        }
    }
    be=max(be, cu);
    cout<<be;
}