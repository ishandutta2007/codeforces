#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define all(x) x.begin(), x.end()

using ll = long long;

const int MAXN = 1e5 + 10;

int b[MAXN], e[MAXN];
int n, L;
int a[MAXN];
int ans[MAXN];

bool check(int mid) {
    int lst = 0;
    for (int i = 0; i < n; i++) {
        int mn = lst + mid;
        if (mn > L) return false;
        if (i+1 < n && mn > a[i+1]) return false;
        if (i+1 == n) mn = L;
        else if (mn < a[i]) mn = a[i];
        lst = ans[i] = mn;
    }
    return true;
}
bool can(int K) {
	int r = 0;
	for(int i = 0; i < n; i++) {
		int rr = min(a[i+1], r + K);
		if(rr < a[i]) return false;
		b[i] = r;
		e[i] = rr;
		r = rr;
	}	

	return r >= L;
}

int intersect(int a, int b, int c, int d){
	int l = max(a, c);
	int r = min(b, d);
	assert(l <= r);
	return l;
}

int l[MAXN], r[MAXN];
int endp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
	a[n] = L;

	int mn, mx;

    int lo = 0, hi = L + 1;
    while (hi - lo > 1) {
        int mid = hi + lo >> 1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
	mn = lo;

	lo = 0, hi = L + 2;
	while(hi - lo > 1) {
		ll mid = (lo + hi) / 2;
		if(can(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	can(hi);
	mx = hi;


	// start

	for(int i = 0; i < n-1; i++){
		l[i+1] = max(a[i], l[i] + mn);
		r[i+1] = min(a[i+1], r[i] + mx);
	}
	
	endp[n-1] = L;

	for(int i = n-1; i > 0; i--){
		int smn = endp[i] - mx;
		int smx = endp[i] - mn;
		
		endp[i-1] = intersect(smn, smx, l[i], r[i]);
	}

	for(int i = 0; i < n; i++){
		int l, r;
		if(i == 0) l = 0;
		else l = endp[i-1];
		r = endp[i];
		cout << l << " " << r << endl;
	}
	

    return 0;
}