#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n,m;
const int N = 1000;
double a[N],b[N];

bool ok(double fuel) {
	for(int i = 0; i < n; ++i) {
		fuel -= (m + fuel)/a[i];
		if(fuel < 0) return false;
		int j = (i+1)%n;
		fuel -= (m + fuel)/b[j];
		if(fuel < 0) return false;
	}
	return true;
}

int main() {	
	fio;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 0; i < n; ++i)
		cin >> b[i];

	double lo = 0;
	double hi = 2e9;
	if(!ok(hi)) {
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < 100; ++i) {
		double md = (lo+hi)/2;
		if(ok(md)) hi = md;
		else lo = md;
	}
	
	cout << setprecision(10) << fixed << lo << "\n";
}