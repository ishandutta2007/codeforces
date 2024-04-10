#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, mod, an=-1, pref=0;
        cin>>n>>mod;
        int l[mod];
        for(int a=0; a<mod; a++) l[a]=-1;
        l[0]=0;
        set <int> se;
        se.insert(0);
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            pref=(pref+x)%mod;
            if(l[pref]==-1) l[pref]=a+1;
            se.erase(l[pref]);
            if(se.size())
            {
                an=max(an, a+1-(*se.begin()));
            }
            se.insert(l[pref]);
        }
        printf("%d\n", an);
    }
}