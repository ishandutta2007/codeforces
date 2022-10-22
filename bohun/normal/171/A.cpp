#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define DOW(i, n) for(int i = n - 1; 0 <= i; --i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

vector <int> b;
int x, y;

int main() {
	cin >> x >> y;
	while(y) {
		b.pb(y % 10);
		y /= 10;
	}
	while(ss(b) && b.back() == 0) b.pop_back();
	int z = 0;
	for(auto it : b)
		z = z * 10 + it;
	cout << x + z;
		
	
		
	return 0;
}