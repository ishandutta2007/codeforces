#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<ll,2> pt;

pt operator-(const pt &a,const pt &b){return {a[0]-b[0],a[1]-b[1]};}
ll cross(pt a,pt b){return (a[0]*b[1]-a[1]*b[0]);}
bool ccw(pt a,pt b,pt c){return (cross(b-a,c-a)>0);}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<ll,3>> v(n);
    vector<pt> points;
    for(int i=0;i<n;i++)
    {
        auto &[x1,x2,y]=v[i];
        cin >> x1 >> x2 >> y;
        points.push_back({x1,y});
        points.push_back({x2,y});
    }
    //build left
    sort(points.begin(),points.end(),[](const pt &a,const pt &b){return (a[1]>b[1]||(a[1]==b[1]&&a[0]<b[0]));});
    vector<pt> one;
    for(auto [x,y]:points)
    {
        while(one.size()>=2&&!ccw(one[one.size()-2],one[one.size()-1],{x,y})) one.pop_back();
        one.push_back({x,y});
    }
    while(one.size()>=2&&one[one.size()-2][1]==one[one.size()-1][1]) one.pop_back();
    vector<pair<double,pt>> l;
    const double inf=1e100;
    for(int i=0;i<(int)one.size()-1;i++)
    {
        auto [x1,y1]=one[i];
        auto [x2,y2]=one[i+1];
        l.push_back({double(x2-x1)/(y1-y2),one[i]});
    }
    l.push_back({inf,one.back()});
    //build right
    reverse(points.begin(),points.end());
    vector<pt> two;
    for(auto [x,y]:points)
    {
        while(two.size()>=2&&!ccw(two[two.size()-2],two[two.size()-1],{x,y})) two.pop_back();
        two.push_back({x,y});
    }
    while(two.size()>=2&&two[two.size()-2][1]==two[two.size()-1][1]) two.pop_back();
    vector<pair<double,pt>> r;
    for(int i=0;i<(int)two.size()-1;i++)
    {
        auto [x1,y1]=two[i];
        auto [x2,y2]=two[i+1];
        r.push_back({double(x1-x2)/(y2-y1),two[i]});
    }
    r.push_back({inf,two.back()});
    //get opt and bad
    vector<double> opt={0};
    vector<array<double,2>> tmp;
    for(auto [xl1,xr1,y1]:v)
    {
        for(auto [xl2,xr2,y2]:v)
        {
            if(y1<=y2) continue;
            double a=double(xl2-xr1)/(y1-y2);
            double b=double(xr2-xl1)/(y1-y2);
            opt.push_back(a);
            opt.push_back(b);
            tmp.push_back({a,b});
        }
    }
    sort(tmp.begin(),tmp.end());
    const double eps=1e-9;
    int idx=0;
    vector<array<double,2>> bad;
    int sz=tmp.size();
    while(idx<sz)
    {
        auto [a,b]=tmp[idx];
        while(idx+1<sz&&tmp[idx+1][0]+eps<=b)
        {
            idx++;
            b=max(b,tmp[idx][1]);
        }
        bad.push_back({a,b});
        idx++;
    }
    //solve
    double res=inf;
    const ll llinf=(1ll<<60);
    for(double o:opt)
    {
        auto it=upper_bound(bad.begin(),bad.end(),array<double,2>{o,-inf});
        bool ok=1;
        if(it!=bad.begin())
        {
            it--;
            auto [a,b]=(*it);
            if(a+eps<=o&&o<=b-eps) ok=0;
        }
        if(ok==0) continue;
        auto [xl,yl]=(*lower_bound(l.begin(),l.end(),make_pair(o,pt{-llinf,-llinf}))).second;
        auto [xr,yr]=(*lower_bound(r.begin(),r.end(),make_pair(o,pt{-llinf,-llinf}))).second;
        res=min(res,(xr+yr*o)-(xl+yl*o));
    }
    cout << fixed << setprecision(9) << res << "\n";
    return 0;
}