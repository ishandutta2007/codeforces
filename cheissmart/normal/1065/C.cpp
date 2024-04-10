#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+87;

ll data[N*4], datb[N*4];

void add(int a, int b, int x, int k, int l, int r){
	if(a <= l && r <= b) {
		data[k] += x;
	}
	else if(l < b && a < r) {
		datb[k] += (min(b, r) - max(a, l)) * x;
		add(a, b, x, k*2+1, l, (l+r)/2);
		add(a, b, x, k*2+2, (l+r)/2, r);
	}
}

ll sum(int a, int b, int k, int l, int r) {
	if(b <= l || r <= a)
		return 0;
	if(a <= l && r <= b)
		return data[k] * (r - l) + datb[k];
	ll res = (min(b, r) - max(a, l)) * data[k];
	res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
	res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
	return res;
}

int a[N];
ll pre[N];

ll _pre(int x) {
	if(x >= 0)
		return pre[x];
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, mnh = INT_MAX, mxh = -INT_MAX, m;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		mnh = min(mnh, a[i]);
		mxh = max(mxh, a[i]);
	}
	m = mxh - mnh;
	for(int i=0;i<n;i++) {
		a[i] -= mnh;
		add(0, a[i], 1, 0, 0, m+1);
	}
	for(int i=0;i<m;i++) {
		pre[i] = sum(0, i+1, 0, 0, m+1);
	}
	int ans = 0;
	for(int i=0;i<m;) {
		int j;
		for(j=i;_pre(j) - _pre(i-1) <= k && j < m;j++);
		i = j;
		ans++;
	}
	cout << ans << endl;
}