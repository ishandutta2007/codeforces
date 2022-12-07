#include <bits/stdc++.h>
#define int long long
using namespace std;
struct el
{
    int p, t, ty;
};
bool comp(el a, el b)
{
    if(a.p!=b.p) return a.p<b.p;
    else return a.ty>b.ty;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, l=0, an=0;
    cin>>n;
    vector <el> sp;
    for(int a=0; a<n; a++)
    {
        int l, r, t;
        scanf("%lld%lld%lld", &l, &r, &t);
        sp.push_back({l+t, t, 1});
        sp.push_back({r, t, -1});
    }
    sort(sp.begin(), sp.end(), comp);
    multiset <int> se;
    for(int a=0; a+1<sp.size(); a++)
    {
        if(sp[a].ty==1)
        {
            l=max(l, sp[a].p-sp[a].t);
            se.insert(sp[a].t);
        }
        else se.erase(se.find(sp[a].t));

        if(se.size())
        {
            int be=*se.begin(), q=(sp[a+1].p-l)/be;
            an+=q, l+=q*be;
        }
    }
    cout<<an;
}