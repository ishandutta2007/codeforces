#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m;
    cin>>n>>k>>m;
    map <string, int> s;
    for(int a=0; a<n; a++)
    {
        string x;
        cin>>x;
        s[x]=a;
    }
    int pr[n], cnu[n], cpr[k];
    for(int a=0; a<n; a++) cin>>pr[a];
    for(int a=0; a<k; a++)
    {
        int q;
        cin>>q;
        cpr[a]=2e9;
        for(int b=0; b<q; b++)
        {
            int i;
            cin>>i;
            i--, cnu[i]=a, cpr[a]=min(cpr[a], pr[i]);
        }
    }
    int an=0;
    for(int a=0; a<m; a++)
    {
        string x;
        cin>>x;
        an+=cpr[cnu[s[x]]];
    }
    cout<<an;
}