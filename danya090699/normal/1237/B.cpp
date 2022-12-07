#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, mi=1e9;
    cin>>n;
    int t[n], pref[n];
    for(int a=0; a<n; a++)
    {
        int i;
        cin>>i;
        i--, t[i]=a;
    }
    for(int a=0; a<n; a++) cin>>pref[a];
    for(int a=n-1; a>=0; a--)
    {
        pref[a]--;
        if(mi<t[pref[a]]) an++;
        mi=min(mi, t[pref[a]]);
    }
    cout<<an;
}