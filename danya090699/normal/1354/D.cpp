#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int pref[n+1];
    for(int a=0; a<=n; a++) pref[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        pref[x]++;
    }
    for(int a=1; a<=n; a++) pref[a]+=pref[a-1];
    int qu[q];
    for(int a=0; a<q; a++) scanf("%d", &qu[a]);
    int l=0, r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1, qnt=pref[mid];
        for(int a=0; a<q; a++)
        {
            if(qu[a]>0) qnt+=(qu[a]<=mid);
            else if(-qu[a]<=qnt) qnt--;
        }
        if(qnt) r=mid;
        else l=mid;
    }
    if(r==n+1) cout<<0;
    else cout<<r;
}