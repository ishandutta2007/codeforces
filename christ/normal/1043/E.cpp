#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int MN = 3e5+2;
struct Dood {
    int x,y,ind;
} dudes[MN];
pii og[MN];
ll xpsa[MN], ypsa[MN], res[MN];
vector<int> hate[MN];
int main() {
    int n,m,a,b;
    scanf ("%d %d",&n,&m);
    for(int i = 1; i <= n; i++) {
        scanf ("%d %d",&dudes[i].x,&dudes[i].y);
        dudes[i].ind = i;
        og[i] = {dudes[i].x,dudes[i].y};
    }
    sort(dudes+1,dudes+1+n,[](Dood a, Dood b) {
        return a.y-a.x < b.y-b.x;
    });
    for (int i = 1; i <= n; i++) xpsa[i] = xpsa[i-1] + dudes[i].x, ypsa[i] = ypsa[i-1] + dudes[i].y;
    while (m--) {
        scanf ("%d %d",&a,&b);
        hate[a].push_back(b);
        hate[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        ll ans = ypsa[i-1] + dudes[i].x * 1LL * (i-1) + xpsa[n]-xpsa[i]+dudes[i].y*1LL*(n-i);
        for (int j : hate[dudes[i].ind]) ans -= min(dudes[i].x+og[j].second,og[j].first+dudes[i].y);
        res[dudes[i].ind] = ans;
    }
    for (int i = 1; i <= n; i++) printf ("%lld%c",res[i]," \n"[i==n]);
    return 0;
}