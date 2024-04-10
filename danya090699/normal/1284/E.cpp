#include <bits/stdc++.h>
using namespace std;
int gty(int x, int y)
{
    if(x!=0) return x<0;
    else return y<0;
}
long long s(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    return 1ll*(x2-x1)*(y2+y1)+1ll*(x3-x2)*(y3+y2)+1ll*(x1-x3)*(y1+y3);
}
bool comp(pair <int, int> a, pair <int, int> b)
{
    int tya=gty(a.first, a.second), tyb=gty(b.first, b.second);
    if(tya!=tyb) return tya<tyb;
    else return s(0, 0, a.first, a.second, b.first, b.second)>0;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++) cin>>ar[a].first>>ar[a].second;
    long long an=0;
    for(int a=0; a<n; a++)
    {
        vector <pair <int, int> > sp;
        for(int b=0; b<n; b++)
        {
            if(a!=b) sp.push_back({ar[b].first-ar[a].first, ar[b].second-ar[a].second});
        }
        sort(sp.begin(), sp.end(), comp);
        for(int b=0; b<n-1; b++)
        {
            pair <int, int> t=sp[b];
            sp.push_back(t);
        }
        int yk=0;
        long long good=(1ll*(n-1)*(n-2)*(n-3)*(n-4))/24;
        for(int b=0; b<n-1; b++)
        {
            if(yk==b) yk++;
            while(s(0, 0, sp[b].first, sp[b].second, sp[yk].first, sp[yk].second)>0) yk++;

            if(yk-b>=4)
            {
                int q=yk-b-1;
                good-=(1ll*q*(q-1)*(q-2))/6;
            }
        }
        an+=good;
    }
    cout<<an;
}