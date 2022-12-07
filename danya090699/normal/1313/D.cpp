#include <bits/stdc++.h>
using namespace std;
struct el
{
    int p, ty, nu;

    bool operator < (el x)
    {
        if(p!=x.p) return p<x.p;
        else return ty<x.ty;
    }
};
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    vector <el> sp;
    for(int a=0; a<n; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        sp.push_back({l, 1, a});
        sp.push_back({r+1, -1, a});
    }
    int dp[1<<k], dp2[1<<k];
    for(int mask=0; mask<(1<<k); mask++) dp[mask]=-1, dp2[mask]=-1;
    dp[0]=0;
    vector <int> ot;
    sort(sp.begin(), sp.end());
    for(int a=0; a<sp.size(); a++)
    {
        int i;
        if(sp[a].ty==-1)
        {
            for(int b=0; b<ot.size(); b++) if(ot[b]==sp[a].nu) i=b;
            ot.erase(ot.begin()+i);
        }
        else
        {
            i=ot.size(), ot.push_back(sp[a].nu);
        }
        for(int mask=0; mask<(1<<k); mask++)
        {
            if(dp[mask]!=-1)
            {

                int va=dp[mask];
                if(__builtin_popcount(mask)&1) va+=(sp[a].p-sp[a-1].p);

                if(sp[a].ty==-1)
                {
                    int to=(mask&((1<<i)-1))+((mask>>(i+1))<<i);
                    dp2[to]=max(dp2[to], va);
                }
                else
                {
                    dp2[mask]=max(dp2[mask], va);
                    dp2[mask+(1<<i)]=max(dp2[mask+(1<<i)], va);
                }
            }
        }
        for(int mask=0; mask<(1<<k); mask++) dp[mask]=dp2[mask], dp2[mask]=-1;
    }
    cout<<dp[0];
}