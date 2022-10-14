#include <bits/stdc++.h>
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; ll x; cin >> n >> x;
    ll st1 = 0, st2 = 0, st3 = 0;
    ll best = 0;
    rep(i, n) {
        ll v; cin >> v;
        ll nst1 = max(0ll, st1) + v, nst2 = max(0ll, max(st1, st2)) + x*v, nst3 = max(st2, st3) + v;
        st1 = nst1; st2 = nst2; st3 = nst3;
        best = max(max(best, st1), max(st2, st3));
    }
    cout << best << endl;
}