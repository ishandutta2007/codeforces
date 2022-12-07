#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int p[n], q[n], an=0;
    for(int a=0; a<n; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        x--, p[x]=a;
    }
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        x--;
        int d=p[x]-a;
        if(d<0) d+=n;
        q[d]++;
        an=max(an, q[d]);
    }
    cout<<an;
}