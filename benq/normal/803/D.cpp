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

int k;
string s;
vi temp;

int ok(int wid) {
	int cur = 0, lst = -1, cind = -1;
	while (1) {
		bool flag = 0;
		while (cind < ((int)temp.size()-1) && temp[cind+1]-lst <= wid) {
			cind++;
			flag = 1;
		}
		if (flag == 0) return MOD;
		cur++;
		lst = temp[cind];
		if (cind == temp.size()-1) break;
	}
	return cur;
}

int main() {
	cin >> k;
	getline(cin,s);
	getline(cin,s);
	F0R(i,s.length()) if (s[i] == '-' || s[i] == ' ') temp.pb(i);
	temp.pb(s.length()-1);
	int lo = 1, hi = 1000000;
	while (lo != hi) {
		int mid = (lo+hi)/2;
		if (ok(mid) <= k) hi = mid;
		else lo = mid+1;
	}
	cout << lo;
}