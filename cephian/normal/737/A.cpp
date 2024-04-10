#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<ll,ll> vii;

vector<pii> v;
vector<pii> cars;
vector<int> g;
int n,k,s,t;

bool ok(int i) {
    int cap = cars[i].second;
    ll tm = 0;
    for(int i = 1; i < g.size(); ++i) {
        ll d = g[i]-g[i-1];
        if(d > cap)
            return false;
        ll a = min(cap-d,d);
        tm += a + 2*(d-a);
        if(tm > t) return false;
    }
    return true;
}

int main() {
    scanf("%d%d%d%d",&n,&k,&s,&t);
    for(int i = 0; i < n; ++i) {
        int c,val;
        scanf("%d%d",&c,&val);
        v.push_back(pii(c,val));
    }
    for(int i = 0; i < k; ++i) {
        int q;
        scanf("%d",&q);
        g.push_back(q);
    }
    g.push_back(0);
    g.push_back(s);
    sort(g.begin(),g.end());
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); ++i) {
        while(!cars.empty() && cars.back().first == v[i].first)
            cars.pop_back();
        if(!cars.empty() && cars.back().second > v[i].second) continue;
        cars.push_back(v[i]);
    }
    int lo = 0,hi=cars.size()-1;
    if(!ok(hi)) {
        printf("-1\n");
        return 0;
    }
    if(ok(lo)) {
        printf("%d\n",cars[lo].first);
        return 0;
    }
    while(lo+1 < hi) {
        int mid = (lo+hi)/2;
        if(ok(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%d\n",cars[hi].first);
    return 0;
}