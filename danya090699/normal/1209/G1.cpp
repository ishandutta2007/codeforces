#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int l[sz], r[sz], add[sz], del[sz];
main()
{
    for(int a=0; a<sz; a++) l[a]=-1, r[a]=-1;
    //freopen("input.txt", "r", stdin);
    int n, q, an=0;
    cin>>n>>q;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(l[ar[a]]==-1) l[ar[a]]=a;
        r[ar[a]]=a+1;
    }
    for(int a=0; a<sz; a++)
    {
        if(l[a]!=-1) add[l[a]]++, del[r[a]]++;
    }
    int pr=0, su=0;
    for(int a=0; a<=n; a++)
    {
        su-=del[a];
        if(su==0)
        {
            map <int, int> ma;
            for(int b=pr; b<a; b++) ma[ar[b]]++;
            int be=0;
            for(auto it=ma.begin(); it!=ma.end(); it++) be=max(be, (*it).second);
            an+=(a-pr)-be;
            pr=a;
        }
        su+=add[a];
    }
    cout<<an;
}