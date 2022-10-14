// writer: piggydan
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ordered_set=tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;
/*
ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout
*/

int n;

vector<int> solve(string s) {
	int t = 0, pt = -1;
	for(char c:s) if(c == 'B') t++;
	vector<int> seq;
	while(seq.size() <= 3*n && t && (pt-t)) {
		pt = t;
		rep(i, n-1) {
			if(s[i] == 'B' && s[i+1] == 'B') {
				seq.push_back(i);
				s[i] = 'W'; s[i+1] = 'W';
				t -= 2;
			}
		}
		for(int i=n-2; i>=0; i--) {
			if(s[i] == 'B' && s[i+1] == 'B') {
				seq.push_back(i);
				s[i] = 'W'; s[i+1] = 'W';
				t -= 2;
			}
			if(s[i] == 'W' && s[i+1] == 'B') {
				seq.push_back(i);
				swap(s[i], s[i+1]);
			}
		}
		rep(i, n-1) {
			if(s[i] == 'B' && s[i+1] == 'B') {
				seq.push_back(i);
				s[i] = 'W'; s[i+1] = 'W';
				t -= 2;
			}
		}
	}
	if(t || seq.size() > 3*n) return {-1};
	return seq;
}

bool fail(vector<int>& t) {
	return (t.size() && t[0] == -1);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	string s; cin >> s;
	vector<int> opt1 = solve(s);
	for(char& c:s) {
		if(c == 'B') c = 'W';
		else c = 'B';
	}
	vector<int> opt2 = solve(s);
	vector<int> seq;
	if(!fail(opt1) && (fail(opt2) || opt1.size() < opt2.size())) seq = opt1;
	else seq = opt2;
	if(fail(seq)) {
		cout << -1 << endl;
		return 0;
	}
	cout << seq.size() << endl;
	if(seq.size()) {
		for(int i:seq) cout << i+1 << ' ';
		cout << endl;
	}
}