#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ALL(x) x.begin(), x.end()
#define vi vector<int>
#define CASE int t;cin>>t;for(int ca=1;ca<=t;ca++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int MAX = 1 << 20, MOD = 1e9 + 7;
ll a[MAX], rd[MAX][5], cnt[MAX], pre[MAX], c[MAX];

mt19937 rng(0x5EED);
int randint(int lb, int ub) {
    return uniform_int_distribution<int>(lb, ub)(rng);
}
ll my_rand(){
    ll res = 0;
    for(int i = 0;i < 50;i++)
        res = (res << 1) | (randint(0,1 ) & 1);
    return res;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        rd[i][1] = my_rand();
        rd[i][2] = my_rand();
        rd[i][3] = rd[i][1] ^ rd[i][2];
    }
    ll l = 1, now = 0, ans = 0;
    map<ll, int> mp;
    mp[0]++;
    for(int i = 1;i <= n;i++){
        cnt[a[i]]++;
        if(cnt[a[i]] > 3)
            cnt[a[i]] = 1;
        now ^= rd[a[i]][cnt[a[i]]];
        c[a[i]]++;
        pre[i] = now;
        while(c[a[i]] > 3){
            mp[pre[l - 1]]--;
            c[a[l++]]--;
        }
        ans += mp[now]++;
    }
    cout << ans << '\n';
}

int main(){
    IOS
    solve();
    return 0;
}