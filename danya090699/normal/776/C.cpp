#include <bits/stdc++.h>
#define int long long
using namespace std;
int mo(int x)
{
    if(x<0) x=-x;
    return x;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, inf=1e15, an=0;
    scanf("%lld%lld", &n, &k);
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    vector <int> po;
    po.push_back(1);
    if(k==0) po.push_back(0);
    else if(k==-1) po.push_back(-1);
    else if(k!=1)
    {
        int cu=k;
        while(mo(cu)<inf)
        {
            po.push_back(cu), cu*=k;
        }
    }
    for(int a=0; a<po.size(); a++)
    {
        int su=po[a], cu=0;
        map <int, int> ma;
        ma[0]=1;
        for(int b=0; b<n; b++)
        {
            cu+=ar[b];
            if(ma.find(cu-su)!=ma.end()) an+=ma[cu-su];
            ma[cu]++;
        }
    }
    cout<<an;
}