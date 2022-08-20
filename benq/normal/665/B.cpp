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
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int n,m,k,z, ans=0;
vi cur;

int f(int x) {
	int c = 0;
	while (cur[c] != x) c++;
	return (c+1);
}

int main() {
	cin >> n >> m >> k;
	FOR(i,1,k+1) {
		cin >> z;
		cur.pb(z);
	}
	
	F0R(i,n) {
		F0R(j,m) {
			cin >> z;
			int d = f(z);
			ans += d;
			cur.erase(cur.begin()+d-1);
			cur.insert(cur.begin(),z);
		}
	}
	cout << ans;
	return 0;
}