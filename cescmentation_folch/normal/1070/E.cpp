#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> ii;

ll m, t;

int calc(VI &p, int mid){
    ll n = p.size();
    ll cnt = 0, add = 0;
    ll done = 0;
    ll time = 0;
    for (int i = 0; i < n and (p[i] > mid or time + p[i] <= t) ; ++i){
        if (p[i] > mid) continue;
        //cerr << p[i] << " " << time << endl;
        ++done;
        time += p[i];
        add += p[i];
        cnt++;
        if (cnt == m){
            time += add;
            add = cnt = 0;
        }
    }
    return done;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int c;
    cin >> c;
    while (c--){
        int n;
        cin >> n >> m >> t;
        VI p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        //cerr << calc(p, 7) << endl;
        //return 0;
        ll l = 1, r = 1e6;
        while (l + 1 != r){
            ll mid = (l+r)/2;
            int pos = 0, done = calc(p, mid);
            for (int i = 0; i < n; ++i) if (p[i] <= mid) ++pos;
            if (done == pos) l = mid;
            else r = mid;
        }
        int pos1 = 0, pos2 = 0;
        for (int i = 0; i < n; ++i) if (p[i] <= l) ++pos1;
        for (int i = 0; i < n; ++i) if (p[i] <= l+1) ++pos2;
        if (calc(p, l) >= calc(p, l+1)) cout << calc(p, l) << " " << min(l, t) << endl;
        else cout << calc(p, l+1) << " " << min(l+1, t) << endl;
    }
}