#include <bits/stdc++.h>
#define int long long
using namespace std;
int s(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (x2-x1)*(y2+y1)+(x3-x2)*(y3+y2)+(x1-x3)*(y1+y3);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x, y;
        scanf("%lld%lld", &x, &y);
        y-=x*x;
        if(ma.find(x)==ma.end()) ma[x]=y;
        else ma[x]=max(ma[x], y);
    }
    vector <pair <int, int> > hull;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int x=(*it).first, y=(*it).second;
        while(hull.size()>1)
        {
            int q=hull.size();
            if(s(hull[q-2].first, hull[q-2].second, hull[q-1].first, hull[q-1].second, x, y)<=0) hull.pop_back();
            else break;
        }
        hull.push_back({x, y});
    }
    cout<<hull.size()-1;
}