#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p;
    cin>>n>>p;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);

    int lg=0, rg=inf;
    while(rg-lg>1)
    {
        int mid=(lg+rg)>>1;
        int q[n], ok=1;
        for(int a=0; a<n; a++) q[a]=0;
        for(int a=0; a<n; a++)
        {
            if(ar[a]<mid) q[0]++;
            else if(ar[a]<mid+n) q[ar[a]-mid]++;
        }
        for(int a=0; a<n; a++)
        {
            if(a) q[a]+=q[a-1]-1;
            if(q[a]==0) ok=0;
        }
        if(ok) rg=mid;
        else lg=mid;
    }
    int l=rg;

    lg=0, rg=inf;
    while(rg-lg>1)
    {
        int mid=(lg+rg)>>1;
        int q[n], ok=1, fo=0;
        for(int a=0; a<n; a++) q[a]=0;
        for(int a=0; a<n; a++)
        {
            if(ar[a]<mid) q[0]++;
            else if(ar[a]<mid+n) q[ar[a]-mid]++;
        }
        for(int a=0; a<n; a++)
        {
            if(a) q[a]+=q[a-1]-1;
            if(q[a]==0) ok=0;
            if(q[a]==p) fo=1;
        }
        if(ok and fo) rg=mid;
        else lg=mid;
    }
    int r=lg;

    cout<<(r-l+1)<<"\n";
    for(int a=l; a<=r; a++) printf("%d ", a);
}