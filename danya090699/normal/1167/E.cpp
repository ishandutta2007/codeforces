#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin>>n>>x;
    int l[x], r[x], pref[x];
    for(int a=0; a<x; a++) l[a]=-1, r[a]=-1, pref[a]=inf;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        x--;
        if(l[x]==-1) l[x]=a;
        r[x]=a;
    }
    if(l[x-1]!=-1) pref[x-1]=l[x-1];
    for(int a=x-2; a>=0; a--)
    {
        if(l[a]==-1) pref[a]=pref[a+1];
        else
        {
            if(r[a]<pref[a+1]) pref[a]=l[a];
            else pref[a]=-inf;
        }
    }
    int yk=0, rg=-inf;
    long long an=0;
    for(int a=0; a<x; a++)
    {
        while(yk<x)
        {
            if(pref[yk]<=rg) yk++;
            else break;
        }
        yk=max(yk, a+1);
        an+=x-yk+1;
        if(l[a]!=-1)
        {
            if(l[a]>rg) rg=r[a];
            else break;
        }

    }
    cout<<an;
}