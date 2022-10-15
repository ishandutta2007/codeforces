#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct point {
    int x;
    int y;
};

ll dist(point a,point b) {
    ll dx=a.x-b.x;
    ll dy=a.y-b.y;
    return dx*dx+dy*dy;
}

const int N=2000+5;

int n;
point a,b;
point v[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    for(int i=1;i<=n;i++) {
        cin>>v[i].x>>v[i].y;
    }
    ll ans=0;
    for(int j=1;j<=n;j++) {
        ans=max(ans,dist(b,v[j]));
    }
    for(int i=1;i<=n;i++) {
        ll dst=dist(a,v[i]);
        ll d2=0;
        for(int j=1;j<=n;j++) {
            if(dist(a,v[j])<=dst) {
                continue;
            }
            d2=max(d2,dist(b,v[j]));
        }
        ll val=d2+dst;
        ans=min(ans,val);
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/