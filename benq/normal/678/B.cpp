#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin()
#define e end()
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

bool leap(int z) {
	if (z % 4 == 0) {
		if (z % 100 == 0) {
			if (z % 400 == 0) return 1;
			else return 0;
		} else return 1;
	} else return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	int y, ans, c;
	cin >> y, ans = y, c = 0;
	while (1) {
		c = (c+365+leap(ans)) % 7;
		if (c == 0 && (leap(y) == leap(ans+1))) {
			cout << (ans+1);
			return 0;
		}
		ans ++;
	}
	return 0;
}