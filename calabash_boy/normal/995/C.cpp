#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
#define inf 2250000000000ll
typedef long long ll;
typedef pair<ll,ll> pll;
#define int long long
typedef vector<int> vi;
typedef pair<pll, int> node;
const int N = 1000000;
int n;
vector<node> a;
inline ll cal(const node &x) {
    return 1ll * x.x.x * x.x.x + 1ll * x.x.y * x.x.y;
}
inline ll dis(ll x, ll y) {
    return x * x + y * y;
}
bool cmp(const node &aa, const node &bb) {
    return cal(aa) < cal(bb);
}
void input(){
    a.resize(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].x.x >> a[i].x.y;
        a[i].y = i;
    }
    sort(all(a),cmp);
}
void solve(){
    ll x=0,y=0;
    ll sx=0,sy=0;
    vi ans(n, 0);
    for(int i=0;i<n;i++) {
        sx+=a[i].x.x;
        sy+=a[i].x.y;
        if(dis(x+a[i].x.x,y+a[i].x.y)<=dis(x,y)) {
            x+=a[i].x.x;
            y+=a[i].x.y;
            ans[a[i].y]=1;
        } else {
            x-=a[i].x.x;
            y-=a[i].x.y;
            ans[a[i].y]=-1;
        }
    }
    while(dis(x,y)>inf) {
        for(int i=n-1;i >= 0;i--) {
            if(ans[a[i].y]==-1) {
                if(dis(x+2*a[i].x.x,y+2*a[i].x.y)>inf)continue;
                x+=2*a[i].x.x;
                y+=2*a[i].x.y;
                ans[a[i].y]=1;
            } else if(ans[a[i].y]==1) {
                if(dis(x-2*a[i].x.x,y-2*a[i].x.y)>inf)continue;
                x-=2*a[i].x.x;
                y-=2*a[i].x.y;
                ans[a[i].y]=-1;
            }
        }
    }
    for (auto t:ans){
        printf("%d ",t);
    }
    puts("");
}
signed main() {
    while (cin >> n) {
        input();
        solve();
    }
    return 0;
}