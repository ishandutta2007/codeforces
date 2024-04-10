#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
set<pii> a;
vector<pii> v, w;
#define F first
#define S second
bool f(pii a, pii b, pii c) {
    return 1LL*(-c.S+a.S)*(b.F-a.F)>1LL*(-b.S+a.S)*(c.F-a.F);
}
int main() {
    int n, m, x, y; scanf("%d%d%d%d", &n, &m, &x, &y);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        a.insert(pii(x,-y));
        v.push_back(pii(x,-y));
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        v.push_back(pii(x,-y));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(pii t: v) {
        while(w.size() && w.back().S>t.S)w.pop_back();
        while(w.size()>1&&f(w[w.size()-2],w.back(),t))w.pop_back();
        w.push_back(t);
    }
    string ans="Min";
    for(pii t: w) if(a.count(t)) { ans="Max"; break; }
    puts(ans.c_str());
    return 0;
}