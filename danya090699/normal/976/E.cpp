#include <bits/stdc++.h>
#define int long long
using namespace std;
bool comp(pair <int, int> a, pair <int, int> b){return a.first-a.second>b.first-b.second;}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, t1, t2;
    cin>>n>>t1>>t2;
    t2=min(t2, n);
    pair <int, int> ar[n];
    for(int a=0; a<n; a++) scanf("%lld%lld", &ar[a].first, &ar[a].second);
    sort(ar, ar+n, comp);
    int add[n], su=0, su2=0;
    for(int a=0; a<n; a++)
    {
        su+=ar[a].second, add[a]=max(0ll, ar[a].first-ar[a].second);
        if(a<t2) su2+=add[a];
    }
    int an=su+su2;
    if(t2>0)
    {
        for(int a=0; a<n; a++)
        {
            int x=ar[a].first;
            for(int b=0; b<t1; b++) x*=2;
            if(a<t2) an=max(an, su+su2-add[a]+max(0ll, x-ar[a].second));
            else an=max(an, su+su2-add[t2-1]+max(0ll, x-ar[a].second));
        }
    }
    cout<<an;
}