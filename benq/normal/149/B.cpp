#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int getval(char c) {
	if ('0' <= c && c <= '9') return c-'0';
	return c-'A'+10;
}

int con (string num, int base) {
	for (char c: num) if (getval(c) >= base) return -1;
	int val = 0;
	F0R(i,num.length()) {
		val = base*val+getval(num[i]);
		if (val>60) return val;
	}
	return val;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string num1, num2;
	bool flag = 0;
	char c;
	while (cin >> c) {
		if (c == ':') flag = 1;
		else if (flag == 0) num1 += c;
		else num2 += c;
	}
	vi ans;
	FOR(i,2,1000) if (0 <= con(num1,i) && con(num1,i) < 24)
		if (0 <= con(num2,i) && con(num2,i) < 60)
			ans.pb(i);
	if (ans.size()>500) cout << -1;
	else if (ans.size() == 0) cout << 0;
	else for (int i: ans) cout << i << " ";
}