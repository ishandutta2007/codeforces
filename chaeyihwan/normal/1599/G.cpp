#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;
const double INF = 1e18;

vector<point> P;
ll ccw(point a, point b, point c)
{
    return (c.y-b.y)*(b.x-a.x) - (b.y-a.y)*(c.x-b.x);
}
double dist(point a, point b)
{
    return sqrt((double)(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    P.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> P[i].first >> P[i].second;
    }

    point S = P[k-1];

    sort(P.begin(), P.end());
    auto last = unique(P.begin(), P.end());
    P.erase(last, P.end());

    n = P.size();
    cout.precision(20);

    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    if(n == 2)
    {
        cout << dist(P[0], P[1]);
        return 0;
    }
    if(n == 3)
    {
        int i;
        for(i=0;i<3;i++) if(S == P[i]) break;
        cout << min(dist(P[i], P[(i+1)%3]),dist(P[i], P[(i+2)%3]))+dist(P[(i+1)%3], P[(i+2)%3]);
        return 0;
    }

    int x = 0;
    if(ccw(P[0], P[1], P[2]) == 0)
    {
        for(int i=3;i<n;i++) if(ccw(P[0], P[1], P[i]) != 0) x = i;
    }
    else if(ccw(P[0], P[1], P[3]) == 0) x = 2;
    else if(ccw(P[0], P[2], P[3]) == 0) x = 1;
    else if(ccw(P[1], P[2], P[3]) == 0) x = 0;

    vector<point> Q;
    point X = P[x];
    for(int i=0;i<n;i++) if(i != x) Q.push_back(P[i]);

    n--;

    if(X == S)
    {
        cout << dist(Q[0], Q[n-1]) + min(dist(X, Q[0]), dist(X, Q[n-1]));
        return 0;
    }
    int f = 0;
    for(int i=0;i<n;i++) if(S == Q[i]) f = i;

    double ans = INF;
    if(f != n-1) ans = min(ans, dist(Q[f+1], Q[n-1]) + dist(X, Q[f+1]) + dist(X, Q[0]) + dist(Q[0], Q[f]));
    if(f != n-1) ans = min(ans, dist(Q[f+1], Q[n-1]) + dist(X, Q[n-1]) + dist(X, Q[0]) + dist(Q[0], Q[f]));
    if(f != 0) ans = min(ans, dist(Q[f], Q[n-1]) + dist(X, Q[n-1]) + dist(X, Q[0]) + dist(Q[0], Q[f-1]));
    if(f != 0) ans = min(ans, dist(Q[f], Q[n-1]) + dist(X, Q[n-1]) + dist(X, Q[f-1]) + dist(Q[0], Q[f-1]));

    vector<point> path;
    double now = 0;
    for(int i=f;i>=0;i--) path.push_back(Q[i]);
    for(int i=f+1;i<n;i++) path.push_back(Q[i]);

    for(int i=1;i<n;i++)
    {
        now += dist(path[i-1], path[i]);
    }

    for(int i=1;i<n;i++)
    {
        ans = min(ans, now - dist(path[i-1], path[i]) + dist(path[i-1], X) + dist(X, path[i]));
    }
    ans = min(ans, now + dist(path[n-1], X));

    path.clear(); now = 0;
    for(int i=f;i<n;i++) path.push_back(Q[i]);
    for(int i=f-1;i>=0;i--) path.push_back(Q[i]);
    for(int i=1;i<n;i++)
    {
        now += dist(path[i-1], path[i]);
    }

    for(int i=1;i<n;i++)
    {
        ans = min(ans, now - dist(path[i-1], path[i]) + dist(path[i-1], X) + dist(X, path[i]));
    }
    ans = min(ans, now + dist(path[n-1], X));
    cout << ans;
}