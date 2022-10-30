#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
ll L[N],p[N],a[N];
double ps[N];

bool cmp(int i, int j) {
	return L[j]*p[j]*(100-p[i]) < L[i]*p[i]*(100-p[j]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		a[i] = i;
		cin >> L[i] >> p[i];
	}
	sort(a,a+n,cmp);
	a[n] = n;
	ps[n] = 0;
	for(int i = n-1; i >= 0; --i)
		ps[a[i]] = ps[a[i+1]] + 1.0-p[a[i]]/100.0;
	double ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += L[a[i]]*(1 + p[a[i]]/100.0*ps[a[i+1]]);
	}
	cout << setprecision(12) << fixed << ans << "\n";
	return 0;
}