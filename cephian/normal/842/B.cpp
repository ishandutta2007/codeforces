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

double eps = 1e-9;
int main() {
	fio;
	ll r,d;
	cin >> r >> d;
	int n,a=0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int x,y,w;
		cin >> x >> y >> w;
		bool cl = sqrt(x*x+y*y) - w <= r-d-eps;
		bool fr = sqrt(x*x+y*y) + w >= r+eps;
		a += !cl && !fr;
	}
	cout << a << "\n";
}