#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 300100;

struct BIT{
    ll bit[N]; BIT(){}
    void upd(int p, int v){for(; p<N; p|=p+1) bit[p] += v;}
    ll sum(int r, ll res = 0){for(; r>=0; r=(r&(r+1))-1) res += bit[r]; return res;}
    ll sum(int l, int r){return sum(r)-sum(l-1);}
} b1, b2;

int n; ll ans, sum;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i<=n; ++i){
        int val; cin >> val;
        ans += sum+1ll*val*(i-1)-b2.sum(val);
        for(int i = 1; i*val<N; ++i)
            ans -= 1ll*val*i*b1.sum(i*val, min((i+1)*val-1, N-1));
        cout << ans << ' '; b1.upd(val, 1); sum += val;
        for(int i = 1; i*val<N; ++i)
            b2.upd(i*val, val*i), b2.upd(min((i+1)*val, N-1), -val*i);
    }
}