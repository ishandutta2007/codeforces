#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
using point=array<ll,2>;

point operator+(const point &a,const point &b){return {a[0]+b[0],a[1]+b[1]};}
point operator-(const point &a,const point &b){return {a[0]-b[0],a[1]-b[1]};}
point rot90(point a){return {-a[1],a[0]};}
ll cross(point a,point b){return (a[0]*b[1]-a[1]*b[0]);}
bool cw(point a,point b,point c){return (cross(b-a,c-a)<0);}
bool ccw(point a,point b,point c){return (cross(b-a,c-a)>0);}

bool good(point a,point b,point c)
{
    point d=b-a;
    point e=rot90(d);
    return (cross(e,c-b)>0);
}

vector<point> convex_hull(vector<point> v)
{
    int n=v.size();
    point tmp=v[0];
    sort(v.begin(),v.end());
    vector<point> up,down;
    point one=v[0];
    point two=v[n-1];
    up.push_back(one);
    down.push_back(one);
    for(int i=1;i<n;i++)
    {
        if(i==n-1||cw(one,v[i],two))
        {
            while(up.size()>=2&&(!cw(up[up.size()-2],up[up.size()-1],v[i]))) up.pop_back();
            up.push_back(v[i]);
        }
        if(i==n-1||ccw(one,v[i],two))
        {
            while(down.size()>=2&&(!ccw(down[down.size()-2],down[down.size()-1],v[i]))) down.pop_back();
            down.push_back(v[i]);
        }
    }
    vector<point> res=up;
    for(int i=(int)down.size()-2;i>0;i--) res.push_back(down[i]);
    vector<point> fin;
    int x=-1;
    for(int i=0;i<(int)res.size();i++) if(res[i]==tmp) x=i;
    assert(x!=-1);
    for(int i=x;i<(int)res.size();i++) fin.push_back(res[i]);
    for(int i=0;i<x;i++) fin.push_back(res[i]);
    return fin;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point> v(n+1,{0,0});
    for(int i=1;i<=n;i++) cin >> v[i][0] >> v[i][1];
    vector<int> res(n+1,0);
    vector<bool> used(n+1,0);
    pair<point,int> m={v[1],1};
    for(int i=2;i<=n;i++) m=min(m,{v[i],i});
    res[1]=m.second;
    used[m.second]=1;
//    cout << "[1]: " << v[res[1]][0] << " " << v[res[1]][1] << endl;
    for(int i=2;i<=n;i++)
    {
        vector<point> opt;
        opt.push_back(v[res[i-1]]);
        for(int j=1;j<=n;j++) if(used[j]==0) opt.push_back(v[j]);
        vector<point> hull=convex_hull(opt);
        int x=-1;
        int sz=hull.size();
//        cout << "hull " << i << endl;
//        for(int j=0;j<sz;j++) cout << hull[j][0] << " " << hull[j][1] << endl;
        for(int j=1;j<sz;j++) if(good(hull[0],hull[j],hull[j-1])&&good(hull[0],hull[j],hull[(j+1)%sz])) x=j;
        assert(x!=-1);
        int id=0;
        for(int j=1;j<=n;j++) if(v[j]==hull[x]) id=j;
        res[i]=id;
        used[id]=1;
//        cout << "[" << i << "]: " << v[res[i]][0] << " " << v[res[i]][1] << endl;
    }
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}