
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> pll;
#define rep(i,l,r) for (int i=l;i<r;i++)
int n;
vector<pll> a;
void input(){
    a.resize(2*n);
    rep(i, 0, n) {
        cin>>a[i].first;
        a[i].second =0;
    }
    rep(i, 0, n) {
        cin>>a[i+n].first;
        a[i+n].second =1;
    }
    sort(a.begin(),a.end());
}
void solve(){ll ans = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        if (a[i + 1].second == 0) {
            //B
            ans += a[i + 1].first;
        }
        if (a[i].second == 1) {
            //A
            ans -= a[i].first;
        }
    }
    cout << ans << endl;
}
int main(){
    cin>>n;
    input();
    solve();
    return 0;
}