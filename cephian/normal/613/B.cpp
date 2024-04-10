#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
ll A,cf,cm,m,after[N],before[N];
int n;

typedef pair<ll,ll> pll;
pll a[N];

ll eval(const pll& p) {
	return cf*p.first + cm*p.second;
}

pll calc(int c) {
	if(after[c] > m) return pll(0,0);
	if(c == 0) return pll(n,A);
	int lo = 1, hi = c+1;
	ll left = m - after[c];
	while(hi-lo>1) {
		int md = (lo+hi)/2;
		((before[md] <= left)?lo:hi) = md;
	}
	ll mnv = min(A,a[lo].first + (left-before[lo])/lo);
	return pll(n-c,mnv);
}

bool cmp2(const pll& a, const pll& b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> A >> cf >> cm >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a+1,a+n+1);
	after[n] = 0;
	for(int i = n-1; i >= 0; --i) {
		after[i] = after[i+1] + A - a[i+1].first;
	}
	before[0] = 0;
	for(int i = 1; i <= n; ++i) {
		before[i] = before[i-1] + (i-1)*(a[i].first-a[i-1].first);
	}
	pll ans(0,0);
	for(int c = 0; c <= n; ++c) {
		pll p = calc(c);
		if(eval(p)>eval(ans))
			ans = p;
	}
	for(int i = 1; i <= n; ++i) {
		a[i].first = max(a[i].first,ans.second);
	}
	for(int i = 0; i < ans.first; ++i) {
		a[n-i].first = max(a[n-i].first,A);
	}
	sort(a+1,a+n+1,cmp2);
	cout << eval(ans) << "\n";
	for(int i = 1; i <= n; ++i) {
		cout << a[i].first << " ";
	}
	cout << "\n";
	return 0;
}