#include <bits/stdc++.h>

#define pb push_back
#define ld long double
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define ull unsigned long long

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

using namespace std;

const int nm = 110;

int n, a[nm], amin, amax, s;
vector<string> r2;

bool kt(int m) {
	if (!m)
		return 1;
	if (s - n * m < 2 * (amax - m))
		return 0;
	return 1;
}

bool cmp(int i, int j) {
	return a[i] > a[j];
}

vector<int> timmax() {
	vector<int> res;
	for (int i = 1; i <= n; ++i) {
		res.pb(i);
	}
	sort(res.begin(), res.end(), cmp);
//	for (int i = 0; i < res.size(); ++i)
//		cout << res[i] << " ";
//	cout << "\n";
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	amin = 101;
	amax = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		amin = min(amin, a[i]);
		amax = max(amax, a[i]);
		s += a[i];
	}
	int res = 0;
	for (int i = amin; i >= 1; --i) {
		if (kt(i)) {
			res = i;
			break;
		}
	}
	cout << res << "\n";
	if (res == 0) {
		while (1) {
			vector<int> tmp = timmax();
			if (a[tmp[0]] == res)
				break;
			string tmp2 = "";
			for (int i = 0; i < n; ++i)
				tmp2 = tmp2 + "0";
			for (int i = 0; i < n && i < 5; ++i) {
				tmp2[tmp[i] - 1] = '1';
				a[tmp[i]] = max(0, a[tmp[i]] - 1);
			}
			r2.pb(tmp2);
		}
		cout << r2.size() << "\n";
		for (int i = 0; i < r2.size(); ++i)
			cout << r2[i] << "\n";
		return 0;
	}
	if ((s - n * res) % 2) {
		vector<int> tmp = timmax();
		string tmp2 = "";
		for (int i = 0; i < n; ++i)
			tmp2 = tmp2 + "0";
		for (int i = 0; i < 3; ++i) {
			tmp2[tmp[i] - 1] = '1';
			a[tmp[i]]--;
		}
		r2.pb(tmp2);

	}
	while (1) {
		vector<int> tmp = timmax();
		if (a[tmp[0]] == res)
			break;
		string tmp2 = "";
		for (int i = 0; i < n; ++i)
			tmp2 = tmp2 + "0";
		tmp2[tmp[0] - 1] = '1';
		a[tmp[0]]--;
		tmp2[tmp[1] - 1] = '1';
		a[tmp[1]]--;
		r2.pb(tmp2);
	}
	cout << r2.size() << "\n";
	for (int i = 0; i < r2.size(); ++i)
		cout << r2[i] << "\n";
#ifdef LOCAL
	printf("\n%.3f s\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}