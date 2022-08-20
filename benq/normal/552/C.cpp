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

int w,m;
	
bool solve(int a) {
	if (a == 0 || a == 1) return true;
	if ((a+1) % w == 0 && solve((a+1)/w)) return true;
	if ((a) % w == 0 && solve((a)/w)) return true;
	if ((a-1) % w == 0 && solve((a-1)/w)) return true;
	
	return false;
}

int main() {
	cin >> w >> m;
	if (solve(m)) cout << "YES";
	else cout << "NO";
	return 0;
}