//time test
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

vector<int> s;
int siz;

void update(int pos, int dif) { // a[pos] += dif
	for (; pos < siz; pos |= pos + 1) s[pos] += dif;
}
int query(int pos) { // sum of values in [0, pos)
	int res = 0;
	for (; pos > 0; pos &= pos - 1) res += s[pos-1];
	return res;
}
int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
	// Returns n if no sum is >= sum, or -1 if empty sum is.
	if (sum <= 0) return -1;
	int pos = 0;
	for (int pw = 1 << 20; pw; pw >>= 1) {
		if (pos + pw <= siz && s[pos + pw-1] < sum)
			pos += pw, sum -= s[pos-1];
	}
	return pos;
}

int main() {
    int n, q, k, j;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    siz=n+1;
    s.resize(n+1);
    rep(i, 0, n+q) {
        cin >> k;
        if(k > 0) {
            update(k, 1);
        } else {
            j = lower_bound(-k);
            update(j, -1);
        }
    }

    int ans = lower_bound(1);
    if(ans > n) ans = 0;
    cout << ans;
}