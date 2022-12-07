#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int i=-30; i<=30; i++)
    {
        int pref=0, su=0, ma=i;
        for(int a=0; a<n; a++)
        {
            if(ar[a]<=i)
            {
                su+=ar[a];
                ma=max(ma, su-pref);
                pref=min(pref, su);
            }
            else pref=0, su=0;
        }
        an=max(an, ma-i);
    }
    cout<<an;
}