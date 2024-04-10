#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

void find(ll* d, ll* arr, int l) {
	fill(d, d+l+1, 1LL<<60);
	for(int i = 0; i < l; ++i) {
		ll sm = 0;
		for(int j = i; j < l; ++j) {
			sm += arr[j];
			int l = j-i+1;
			d[l] = min(d[l], sm);
		}
	}
}

const int N = 2005;
ll a[N];
ll A[N];
ll b[N];
ll B[N];

int main() {
	fio;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	ll x;
	cin >> x;
	find(A, a, n);
	find(B, b, m);
	ll best = 0;
	for(ll la = 1; la <= n; ++la) {
		for(ll lb = 1; lb <= m; ++lb) {
		//cout << la << " - " << A[la] << endl;
			if(A[la]*B[lb] <= x) {
				best = max(ll(best), la * lb);
			}
		}
	}
	cout << best << "\n";	

}