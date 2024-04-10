#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int k[3];
    for(int i=0; i<3; i++) cin>>k[i];
    int n=k[0]+k[1]+k[2];
    int ar[n];
    for(int i=0; i<3; i++)
    {
        for(int a=0; a<k[i]; a++)
        {
            int p;
            scanf("%d", &p);
            p--, ar[p]=i;
        }
    }
    int suf[n+1], be[n+1];
    suf[n]=0, be[n]=0;
    for(int a=n-1; a>=0; a--)
    {
        suf[a]=suf[a+1];
        if(ar[a]==2) suf[a]++;
        if(ar[a]==1) suf[a]--;
        be[a]=max(suf[a], be[a+1]);
    }
    int an=n, va=k[1];
    for(int a=0; a<=n; a++)
    {
        //if(a==3) cout<<be[a];
        an=min(an, n-va-be[a]);
        if(a<n)
        {
            if(ar[a]==0) va++;
            if(ar[a]==1) va--;
        }
    }
    cout<<an;
}