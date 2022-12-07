#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    pair <int, pair <int, int> > ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a].first);
        ar[a].second.second=a;
    }
    for(int a=0; a<n; a++) scanf("%lld", &ar[a].second.first);
    sort(ar, ar+n);
    multiset <int> se;
    int su=0, an[n];
    for(int a=0; a<n; a++)
    {
        int i=ar[a].second.second, va=ar[a].second.first;
        an[i]=va+su;
        if(se.size()<k)
        {
            se.insert(va), su+=va;
        }
        else
        {
            if(k>0)
            {
                if((*se.begin())<va)
                {
                    su-=(*se.begin());
                    se.erase(se.begin());
                    su+=va;
                    se.insert(va);
                }
            }
        }
    }
    for(int a=0; a<n; a++) printf("%lld ", an[a]);
}