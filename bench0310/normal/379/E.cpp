#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef array<long double,2> point;
const long double eps=1e-9;

point intersect(point a,point b,point c,point d)
{
    ld mone=(b[1]-a[1])/(b[0]-a[0]);
    ld mtwo=(d[1]-c[1])/(d[0]-c[0]);
    ld bone=a[1]-mone*a[0];
    ld btwo=c[1]-mtwo*c[0];
    if(abs(mone-mtwo)<eps) return {-1,-1};
    ld x=(btwo-bone)/(mone-mtwo);
    ld y=mone*x+bone;
    if((a[0]-eps<=x&&x<=b[0]+eps)&&(c[0]-eps<=x&&x<=d[0]+eps)) return {x,y};
    else return {-1,-1};
}

set<array<long long,2>> s[300];
vector<point> convex[300];
vector<ld> area(300,0);

void ar(int idx)
{
    area[idx]=0;
    vector<point> &v=convex[idx];
    for(int i=0;i<(int)v.size()-1;i++) area[idx]+=(v[i+1][0]-v[i][0])*((v[i+1][1]+v[i][1])/2);
}

void update(int idx,long long l,long long r)
{
    if(s[idx].find({l,r})!=s[idx].end()) return;
    s[idx].insert({l,r});
    vector<point> &v=convex[idx];
    point pl={0,l};
    point pr={1,r};
    if(l>=v[0][1]&&r>=v.back()[1])
    {
        v.clear();
        v.push_back(pl);
        v.push_back(pr);
    }
    else if(l>=v[0][1])
    {
        point pi={-1,-1};
        for(int i=0;i<(int)v.size()-1;i++)
        {
            point p=intersect(v[i],v[i+1],pl,pr);
            if(p[0]!=-1) pi=p;
        }
        vector<point> t;
        t.push_back(pl);
        if(abs(pl[0]-pi[0])>eps) t.push_back(pi);
        for(int i=0;i<(int)v.size();i++) if(v[i][0]>pi[0]) t.push_back(v[i]);
        v=t;
    }
    else if(r>=v.back()[1])
    {
        point pi={-1,-1};
        for(int i=v.size()-1;i>=1;i--)
        {
            point p=intersect(v[i-1],v[i],pl,pr);
            if(p[0]!=-1) pi=p;
        }
        vector<point> t;
        for(int i=0;i<(int)v.size();i++) if(v[i][0]<pi[0]) t.push_back(v[i]);
        if(abs(pr[0]-pi[0])>eps) t.push_back(pi);
        t.push_back(pr);
        v=t;
    }
    else
    {
        vector<point> pi;
        for(int i=0;i<(int)v.size()-1;i++)
        {
            point p=intersect(v[i],v[i+1],pl,pr);
            if(p[0]!=-1)
            {
                if(pi.empty()||abs(pi.back()[0]-p[0])>eps) pi.push_back(p);
            }
        }
        if(pi.size()==2)
        {
            vector<point> t;
            for(int i=0;i<(int)v.size();i++) if(v[i][0]<pi[0][0]) t.push_back(v[i]);
            t.push_back(pi[0]);
            t.push_back(pi[1]);
            for(int i=0;i<(int)v.size();i++) if(v[i][0]>pi[1][0]) t.push_back(v[i]);
            v=t;
        }
    }
    ar(idx);
}

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        convex[i].push_back({0,0});
        convex[i].push_back({1,0});
    }
    cout << fixed << setprecision(12);
    for(int i=0;i<n;i++)
    {
        ld res=0;
        vector<long long> x(k+1,0);
        for(int j=0;j<=k;j++) scanf("%I64d",&x[j]);
        for(int j=0;j<k;j++)
        {
            res-=area[j];
            update(j,x[j],x[j+1]);
            res+=area[j];
        }
        /*cout << "after update:" << endl;
        for(int j=0;j<k;j++)
        {
            cout << "j=" << j << endl;
            for(point z:convex[j]) cout << z[0] << " " << z[1] << endl;
        }*/
        printf("%.12Lf\n",res);
    }
    return 0;
}