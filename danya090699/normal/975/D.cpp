#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, b, an=0;
    cin>>n>>k>>b;
    map <int, vector < pair <int, int> > > ma;
    for(int a=0; a<n; a++)
    {
        int x, vx, vy;
        scanf("%lld%lld%lld", &x, &vx, &vy);
        int y=k*x+b;
        int x2=x+vx, y2=y+vy;
        int b2=y2-k*x2;
        if(vx!=0 and vy!=0)
        {
            int d=__gcd(abs(vx), abs(vy));
            vx/=d, vy/=d;
        }
        ma[b2].push_back(make_pair(vx, vy));
    }
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        vector <pair <int, int> > &ve=(*it).second;
        map <pair <int, int>, int> ma2;
        for(int a=0; a<ve.size(); a++) ma2[ve[a]]++;
        for(auto it2=ma2.begin(); it2!=ma2.end(); it2++) an+=((*it2).second)*(ve.size()-(*it2).second);
    }
    cout<<an;
}