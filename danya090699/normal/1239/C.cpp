#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p;
    cin>>n>>p;
    vector <pair <int, int> > sp;
    queue <int> qu;
    set <int> se, us;
    us.insert(inf);
    int an[n];
    for(int a=0; a<n; a++)
    {
        int t;
        scanf("%lld", &t);
        sp.push_back({t, a});
    }
    sort(sp.begin(), sp.end());
    reverse(sp.begin(), sp.end());

    while(sp.size() or qu.size())
    {
        int t1=inf, t2=inf;
        if(qu.size()) t1=an[qu.front()];
        if(sp.size()) t2=sp.back().first;

        if(t1<t2)
        {
            us.erase(qu.front());
            qu.pop();
        }
        else
        {
            se.insert(sp.back().second);
            sp.pop_back();
        }
        int t=min(t1, t2);
        if(se.size() and (*se.begin())<(*us.begin()))
        {
            int i=*se.begin();
            an[i]=t;
            if(qu.size()) an[i]=an[qu.back()];
            an[i]+=p;
            qu.push(i);
            us.insert(i);
            se.erase(se.begin());
        }
    }
    for(int a=0; a<n; a++) printf("%lld ", an[a]);
}