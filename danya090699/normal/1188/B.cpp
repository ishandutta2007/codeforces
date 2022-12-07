#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p, k;
    cin>>n>>p>>k;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        int st2=(1ll*x*x)%p;
        ma[(1ll*st2*st2-(1ll*x*k)%p+p)%p]++;
    }
    long long an=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int q=(*it).second;
        an+=1ll*q*(q-1)/2;
    }
    cout<<an;
}