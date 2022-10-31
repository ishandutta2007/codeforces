#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const ll N = 50;
vl cnt(N >> 1, 0), fact(N, 0), a( N >> 1, 0);
ll n;
ll spj(){
    ll res = 1,sum = 0;
    for(ll v: a) {
        sum += v;
    }
    for(ll i = 0; i <=9; i++) {
        res *= ((fact[sum] / fact[a[i]] / fact[sum - a[i]]));
        sum -= a[i];
    }
    if(a[0]) {
        a[0]--;
        ll ress = 1,summ = 0;
        for(ll v: a)summ += v;
        for(ll i = 0; i <=9; i++) {
            ress *= ((fact[summ] / fact[a[i]] / fact[summ - a[i]]));
            summ -= a[i];
        }
        res-=ress;
        a[0]++;
    }
    return res;
}
ll solve(ll x) {
    if(x == 10) {
        return spj();
    }
    if(cnt[x] == 0) {
        a[x] = 0;
        return solve(x + 1);
    }
    ll res = 0;
    for(ll i = 1;i <= cnt[x];i++) {
        a[x] = i;
        res += solve(x + 1);
    }
    return res;
}
void init(){
    fact[0] = 1;
    for(ll i=1;i<N;++i) {
        fact[i]=fact[i-1]*i;
    }
    while (n){
        cnt[n%10]++;
        n/=10;
    }
}
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    init();
    cout << solve(0) << endl;
    return 0;
}