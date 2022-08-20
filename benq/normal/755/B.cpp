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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m; cin >> n >> m;
	int a1=0,b1=0,c1=0;
	set<string> a,b;
	F0R(i,n) {
		string s; cin >> s;
		a.insert(s);
		a1++;
	}
	F0R(i,m) {
		string s; cin >> s;
		if (a.find(s) != a.end()) a1--, c1++;
		else b1++;
	}
	c1 %= 2;
	if ((a1+c1) <= b1) cout << "NO";
	else cout << "YES";
}