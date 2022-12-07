#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, first;
    cin>>n;
    vector <pair <int, int> > mi(1), ma(1);
    cin>>first;
    mi[0]={first, 0}, ma[0]={first, 0};
    for(int a=1; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        int dp=1e9;
        while(mi.size())
        {
            dp=min(dp, mi.back().second+1);
            if(mi.back().first>x) mi.pop_back();
            else
            {
                if(mi.back().first==x) mi.pop_back();
                break;
            }
        }
        while(ma.size())
        {
            dp=min(dp, ma.back().second+1);
            if(ma.back().first<x) ma.pop_back();
            else
            {
                if(ma.back().first==x) ma.pop_back();
                break;
            }
        }
        mi.push_back({x, dp});
        ma.push_back({x, dp});

        if(a==n-1) cout<<dp;
    }
}