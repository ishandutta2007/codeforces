#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0);
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int main()
{
	fast_cin();
	int s, b;
	cin >> s >> b;
	vector<pii> A(s), B(b);
	vector<int> ans(s);
	for (int i = 0; i < s; ++i) {
		cin >> A[i].first;
		A[i].second = i;
	}
	for (int i = 0; i < b; ++i) {
		cin >> B[i].first >> B[i].second;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ll p = 0, cur = 0;
	for (int i = 0; i < s; ++i) {
		while (p < b and B[p].first <= A[i].first) {
			cur += B[p].second;
			++p;
		}
		ans[A[i].second] = cur;
	}
	for (int i = 0; i < s; ++i) {
		cout << ans[i] << ' ';
	}

	cout << endl;
}