#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int q[n], pr[n];
    for(int a=0; a<n; a++) scanf("%lld", &q[a]);
    vector <pair <int, int> > sp;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &pr[a]);
        sp.push_back({pr[a], a});
    }
    sort(sp.begin(), sp.end(), greater <pair <int, int> >());
    for(int a=0; a<m; a++)
    {
        int ty, d, an=0;
        scanf("%lld%lld", &ty, &d);
        ty--;
        int qq=min(q[ty], d);
        q[ty]-=qq, d-=qq, an+=qq*pr[ty];
        while(d and sp.size())
        {
            int ty2=sp.back().second;
            qq=min(q[ty2], d);
            q[ty2]-=qq, d-=qq, an+=qq*pr[ty2];
            if(q[ty2]==0) sp.pop_back();
        }
        if(d) an=0;
        printf("%lld\n", an);
    }
}