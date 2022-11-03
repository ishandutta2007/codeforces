#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <sstream>

using namespace std;

struct pt {
    double x, y;
};

bool cmp (pt a, pt b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
    if (a.size() == 1)  return;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
}

int solve(int n,int m) {
    vector <pt> v,vv;
    double a,b; int ans=0;
    while(n--) {
        cin >> a >> b;
        pt p={a,b};
        v.push_back(p);
    }
    for(int mask=1;mask<(1<<v.size());++mask) {
        vv.clear();
        for(int i=0;i<v.size();++i)
            if (mask&(1<<i))
                vv.push_back(v[i]);
        convex_hull(vv);
        if (vv.size()>m) {
            for(int i=0;i<vv.size();++i)
                cout << (int)vv[i].x << "   " << (int)vv[i].y << endl;
            cout << endl;
        }
        ans=max(ans,(int)vv.size());
    }
    return ans;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
//  cout << solve(n,m) << endl;
    if (m==3&&(n==6||n==5)) {
        puts("-1");
        return 0;
    }
    cout << "-10000 0\n100000000 0\n";
    int r=n-m;
    int sx=-10000,sy=10000000,x1,y1;
    int cx=sx,cy=sy,add=1,last=100000;
    for(int i=0;i<m-2;++i) {
        x1=cx; y1=cy;
        cout << cx << " " << cy << endl;
        cx+=10*add+(i<=m-4 ? last : 0); add++; cy++;
    }
    m=min(m-2,r);
    int x2,y2;
    cx=sx+2,cy=sy-1000005,add=1;
    for(int i=0;i<m;++i) {
        x2=cx; y2=cy;
        cout << cx << " " << cy << endl;
        cx+=5*add+(i<=m-2 ? last : 0); add++; cy++;
    }
/*  m=(r)/2;
//  cout << x1+1LL*(x2-x1)*(y1/(y1-y2)+2) << endl;
    cx=max(x1+(x2-x1)*(y1/(y1-y2)+2)+5,sx+5),cy=1,add=1;
//  cout << endl;
    for(int i=0;i<m;++i) {
        cout << cx << " " << cy << endl;
        cx+=add; add++; cy++;
    }*/
    r-=m;
    cx=sx+2,cy=sy-1000006;
    if (r) {
        cout << cx << " " << cy << endl;
        --r;
        if (r) {
            cx=x2; cy=y2-1;
            cout << cx << " " << cy << endl;
        }
    }
    return 0;
}