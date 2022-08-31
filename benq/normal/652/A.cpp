#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	int h1, h2, a,b;
	cin >> h1 >> h2 >> a >> b;
	h1 += 8*a;
	if (h1 >= h2) {
		cout << 0;
		return 0;
	}
	int rate = 12*a-12*b;
	if (rate <= 0) {
		cout << -1;
		return 0;
	} else {
		if ((h2-h1) % rate == 0) {
			cout << (h2-h1)/rate;
		} else cout << ((h2-h1)/rate+1);
	}
	return 0;
}