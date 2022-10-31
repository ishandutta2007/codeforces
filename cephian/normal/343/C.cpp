#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n,m;
const int N = 100005;
ll h[N],p[N];

ll takes(ll a, ll b) {
    return (a<b)?b-a:a-b;
}

ll how_long(ll a, ll b ,ll c) {
    return min(takes(a,b)+takes(b,c),takes(a,c)+takes(c,b));
}

bool can_do(ll t) {
    int j = 0;
    for(int i = 0; i < n; ++i) {
        int k = j;
        while(k < m && how_long(h[i],p[j],p[k]) <= t) ++k;
        j=k;
        if(j==m) break;
    }
    return j == m;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    for(int i = 0; i < m; ++i)
        cin >> p[i];
    sort(h,h+n);
    sort(p,p+m);
    ll lo = 0, hi=1e12;
    if(can_do(0)) {
        cout << "0\n";
        return 0;
    }
    while(lo+1 < hi) {
        ll mid = (lo+hi)/2;
        if(can_do(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << "\n";
}