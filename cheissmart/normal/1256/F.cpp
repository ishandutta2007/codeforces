#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[200005], b[200005], t[200005];

int c(int l, int r, int* a) { // [l, r)
	if(l == r-1) return 0;
	int ans = 0,m = (l + r + 1) / 2, k = l, ct = 0;
	ans += c(l, m, a) + c(m, r, a);
	for(int i=l, j=m;i < m || j < r;) {
		if(j >= r || (i < m && a[i] <= a[j])){
			t[k++] = a[i++];
			ct++;
		}
		else {
			t[k++] = a[j++];
			ans += m-l-ct;
		}
	}
	for(int i=l;i<r;i++)
		a[i] = t[i];
	return ans;

}

bool solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	string ss = s, tt = t;
	sort(ALL(ss)), sort(ALL(tt));
	if(ss != tt) {
		return false;
	}
	for(int i=0;i<n-1;i++) {
		if(ss[i] == ss[i+1]) {
			return true;
		}
	}
	for(int i=0;i<n;i++) {
		a[i] = lower_bound(ALL(ss), s[i]) - ss.begin();
		b[i] = lower_bound(ALL(ss), t[i]) - ss.begin();
	}
	int c1 = c(0, n, a), c2 = c(0, n, b);
	return (c1 & 1) == (c2 & 1);
}

signed main()
{
	IO_OP;

	int q;
	cin >> q;
	while(q--){
		if(solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	
}