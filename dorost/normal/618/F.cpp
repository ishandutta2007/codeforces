/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1000012;
int a[N], b[N];
ll psa[N], psb[N];
vector <int> v[N], v2[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], v[a[i]].push_back(i);
	for (int i = 0; i < n; i++)
		cin >> b[i], v2[b[i]].push_back(i);
	sort(a, a + n);
	sort(b, b + n);
	psa[0] = a[0];
	psb[0] = b[0];
	for (int i = 1; i < n; i++) {
		psa[i] = psa[i - 1] + a[i];
	}
	int lst = 0;
	for (int i = 1; i < n; i++) {
		psb[i] = psb[i - 1] + b[i];
		while (psa[lst] < psb[i])
			lst++;
		int in = lst;
		if (in != n && psa[in] == psb[i]) {
			cout << in + 1 << '\n';
			for (int j = 0; j <= in; j++) {
				cout << v[a[j]].back() + 1 << ' ';
				v[a[j]].pop_back();
			}
			cout << '\n' << i + 1 << '\n';
			for (int j = 0; j <= i; j++) {
				cout << v2[b[j]].back() + 1 << ' ';
				v2[b[j]].pop_back();
			}
			return 0;
		}
	}
	reverse(a, a + n);
	reverse(b, b + n);
	psa[0] = a[0];
	psb[0] = b[0];
	for (int i = 1; i < n; i++) {
		psa[i] = psa[i - 1] + a[i];
	}
	lst = 0;
	for (int i = 1; i < n; i++) {
		psb[i] = psb[i - 1] + b[i];
		while (psa[lst] < psb[i])
			lst++;
		int in = lst;
		if (in != n && psa[in] == psb[i]) {
			cout << in + 1 << '\n';
			for (int j = 0; j <= in; j++) {
				cout << v[a[j]].back() + 1 << ' ';
				v[a[j]].pop_back();
			}
			cout << '\n' << i + 1 << '\n';
			for (int j = 0; j <= i; j++) {
				cout << v2[b[j]].back() + 1 << ' ';
				v2[b[j]].pop_back();
			}
			return 0;
		}
	}
}