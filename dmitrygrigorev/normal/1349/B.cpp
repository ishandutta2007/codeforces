#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define aint(a) a.begin(), a.end()

using namespace std;

vector<int> t;
int e;

void init (int nn)
{
	e = nn;
	t.assign (e, 0);
}

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < e; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}




int get(vector<int> x, int t) {

	int n = x.size();

	for (int i = 0; i < n; ++i) {
		if (x[i] <= t) x[i] = 1;
		else x[i] = -1;
	}

	init(2*n+7);
	int mid = n+3;

	inc(mid + 0, 1);
	int ans = 0;
	int cur = 0;

	for (int i = 0; i < n; ++i) {
		cur += x[i];
		ans += sum(0, mid+cur);
		//cout <<  " === " << ans << endl;
		inc(mid+cur, 1);
	}

	return ans;


}

void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	map<int, int> ms;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		ms[v[i]]++;
	}

	if (n == 1) {
		if (v[0] == k) cout << "yes\n";
		else cout << "no\n";
		return;
	}

	int A = get(v, k-1);
	int B = get(v, k) - ms[k];

	int more = n*(n+1)/2 - B;
	for (int i = 0; i < n; ++i) if (v[i] >= k) more--;

	//cout << get(v, k-1) << " " << get(v, k) << endl;

	if ((A==B && more == 0) || ms[k] == 0) cout << "no\n";
	else cout << "yes\n";

}

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}