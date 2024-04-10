

//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cerr<<"[debug] "<<#x<<":"<<x<<endl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = 2e5+100;
const int MOD = 1e9+7;
typedef long long ll;
ll n, q;
ll solve1(ll n, ll l, ll r) {
    ll res=(n*n+1)/2;
    if (n%2){
        res+=((l - 1) / 2) * (n / 2 + n / 2 + 1);
        if (l & 1) return res + r / 2;
        else return res + (n / 2) + (r + 1) / 2;
    }
    else{
        return res + (l - 1) * (n / 2) + (r + 1) / 2;
    }

}
ll l, r;
ll solve2(ll n, ll l, ll r) {
    if (n % 2) {
        ll res = ((l - 1) / 2) * (n / 2 + n / 2 + 1);
        if (l & 1) {
            return res + (r + 1) / 2;
        }
        else {
            return res + (n / 2 + 1) + r / 2;
        }
    }
    else {
        return  (l - 1) * (n / 2) + (r + 1) / 2;
    }
}
void work(){
    cin >> l >> r;
    ll ans = -1;
    if ((l + r) % 2) {
        ans = solve1(n, l, r);
    } else {
        ans = solve2(n, l, r) ;
    }
    cout<<ans<<"\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    while (q--) {
        work();
    }
    return 0;
}