#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define pb push_back
#define pii pair <int, int>

#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second

int n, ans = 0;
vector<pair<int,char>> x;
string s;

int main() {
	cin >> n >> s;	
	F0R(i,n) if (s[i] != '.') x.pb(mp(i,s[i]));
	if (x.size() == 0) {
		cout << n;
		return 0;
	}
	if (x[0].s == 'R') x.insert(x.begin(),mp(-1,'L'));
	if (x[x.size()-1].s == 'L') x.pb(mp(n,'R'));
	F0R(i,x.size()-1) if (x[i].s == 'R') {
		if ((x[i+1].f-x[i].f) % 2 == 0) ans++;
	} else ans += (x[i+1].f-x[i].f-1);
	cout << ans;
}