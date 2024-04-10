#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int L,R,U,D;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s; cin >> s;
	if (s.length() % 2) {
		cout << -1;
		return 0;
	}
	for (char i: s) {
		if (i == 'L') L++;
		else if (i == 'R') R++;
		else if (i == 'U') U++;
		else D++;
	}
	cout << (abs(L-R)+abs(U-D))/2;
}