#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define f first
#define s second

pii slope(pii a, pii b){
    pii res = {a.f-b.f, a.s-b.s};
    int gd = __gcd(abs(a.f-b.f), abs(a.s-b.s));
    res.f /= gd, res.s /= gd;
    if(res.f<0 || (res.f==0 && res.s<0))
        res.f = -res.f, res.s = -res.s;
    return res;
}

double dist(pii a, pii b){
    return sqrt(1ll*(a.f-b.f)*(a.f-b.f)+1ll*(a.s-b.s)*(a.s-b.s));
}

int main(){
    // freopen("a.in", "r", stdin);
    cout << fixed << setprecision(10);
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k; --k;
    vector<pii> points(n);
    for(int i = 0; i<n; ++i)
        cin >> points[i].f >> points[i].s;
    set<pii> check;
    for(int i = 1; i<n; ++i)
        check.insert(slope(points[0], points[i]));
    pii bad; int id_bad;
    if((int)check.size()==n-1)
        bad = points[0], id_bad = 0;
    else{
        assert((int)check.size()==2);
        vector<int> tmp1, tmp2;
        pii s1 = (*check.begin()), s2 = (*check.rbegin());
        for(int i = 1; i<n; ++i)
            if(slope(points[0], points[i])==s1) tmp1.push_back(i);
            else tmp2.push_back(i);
        if(tmp2.size()<tmp1.size()) swap(tmp1, tmp2);
        assert((int)tmp1.size()==1);
        bad = points[tmp1.back()], id_bad = tmp1.back();
    }
    pii bruh;
    if(k==id_bad) k = n-1;
    else bruh = points[k], k = -1;
    vector<pii> line;
    for(int i = 0; i<n; ++i)
        if(i!=id_bad) line.push_back(points[i]);
    --n;
    sort(line.begin(), line.end());
    if(k!=n)
        for(int i = 0; i<n; ++i)
            if(line[i]==bruh) k = i;
    double ans = 1e18;
    if(k==n){
        ans = min(ans, dist(bad, line.back())+dist(line.front(), line.back()));
        ans = min(ans, dist(bad, line.front())+dist(line.front(), line.back()));
        cout << ans << '\n';
        return 0;
    }
    for(int i = k; i<n; ++i){
        double lol = 0;
        if(i<n-1) lol = dist(bad, line[i+1])+dist(line[i+1], line[n-1]);
        ans = min(ans, dist(line[k], line[i])+dist(line[i], line[0])+dist(line[0], bad)+lol),
        ans = min(ans, dist(line[k], line[0])+dist(line[0], line[i])+dist(line[i], bad)+lol);
    }
    for(int i = 0; i<=k; ++i){
        double lol = 0;
        if(i>0) lol = dist(bad, line[i-1])+dist(line[i-1], line[0]);
        ans = min(ans, dist(line[k], line[i])+dist(line[i], line[n-1])+dist(line[n-1], bad)+lol),
        ans = min(ans, dist(line[k], line[n-1])+dist(line[n-1], line[i])+dist(line[i], bad)+lol);
    }
    cout << ans << '\n';
}