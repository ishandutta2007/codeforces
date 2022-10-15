#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point
{
        ll x;
        ll y;
};

ll f(point a, point b)
{
        return (a.x-b.x)*(a.y+b.y);
}

ll f(point a, point b, point c)
{
        return f(a, b)+f(b, c)+f(c, a);
}

bool operator < (point a, point b)
{
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
}

point inv(point a)
{
        a.y*=-1;
        return a;
}

set<point> hull[2];

bool under(int id, point p)
{
        auto it=hull[id].lower_bound(p);
        if (it==hull[id].end()) return 0;
        if (it==hull[id].begin()) return (it->x==p.x);
        auto nxt=it;
        it--;
        auto ant=it;
        return f(*ant, p, *nxt)>=0;
}

bool inside(point p)
{
        return under(0, p)&&under(1, inv(p));
}

bool bad(int id, set<point>::iterator it)
{
        if (it==hull[id].begin()||it==hull[id].end()) return 0;
        point a, b, c;
        b=*it;
        it--;
        a=*it;
        it++;
        it++;
        if (it==hull[id].end()) return 0;
        c=*it;
        return f(a, b, c)>=0;
}

void add(int id, point p)
{
        if (under(id, p)) return;
        hull[id].insert(p);

        auto it=hull[id].find(p); it++;
        while (bad(id, it))
        {
                point del=*it; it++;
                hull[id].erase(del);
        }

        it=hull[id].find(p); if (it!=hull[id].begin()) it--;
        while (bad(id, it))
        {
                point del=*it; it--;
                hull[id].erase(del);
        }
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
                int type, x, y;
                cin>>type>>x>>y;
                point p={x, y};
                if (type==2)
                {
                        if (inside(p))
                        {
                                cout<<"YES\n";
                        }
                        else
                        {
                                cout<<"NO\n";
                        }
                        continue;
                }
                add(0, p);
                add(1, inv(p));
        }
        return 0;
}