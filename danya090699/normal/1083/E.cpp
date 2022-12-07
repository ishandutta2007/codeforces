#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
struct pr
{
    int x, y, a;
};
bool comp(pr a, pr b){return a.x<b.x;}

int de(int x, int y){return x/y+(x%y>0);}
struct el
{
    int k, b, r;
    operator < (const el &x) const
    {
        return r>x.r;
    }
};
void hull_ins(vector <el> &hull, int k, int b)
{
    while(hull.size())
    {
        int k2=hull.back().k, b2=hull.back().b, r2=hull.back().r, r;
        if(k==k2)
        {
            if(b>b2) break;
            else hull.pop_back();
        }
        else
        {
            if(b<=b2) r=(b2-b)/(k-k2);
            else r=-de(b-b2, k-k2);

            if(r>=r2) hull.pop_back();
            else
            {
                hull.push_back({k, b, r});
                break;
            }
        }
    }
    if(hull.size()==0) hull.push_back({k, b, inf});
}
int hull_que(vector <el> &hull, int x)
{
    el cu={0, 0, x};
    int p=upper_bound(hull.begin(), hull.end(), cu)-hull.begin()-1;
    return hull[p].k*x+hull[p].b;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    pr ar[n];
    for(int a=0; a<n; a++) scanf("%lld%lld%lld", &ar[a].x, &ar[a].y, &ar[a].a);
    sort(ar, ar+n, comp);
    vector <el> hull;
    hull_ins(hull, 0, 0);
    for(int a=0; a<n; a++)
    {
        int dp=ar[a].x*ar[a].y-ar[a].a-hull_que(hull, ar[a].y);
        an=max(an, dp);
        int k=-ar[a].x, b=dp;
        hull_ins(hull, -k, -b);
    }
    cout<<an;
}