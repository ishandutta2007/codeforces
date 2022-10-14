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

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	rep(i, t) {
		string s; cin >> s;
		vector<int> v;
		for(int i=0; i+4<s.length(); i++) {
			if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e') {
				v.push_back(i+2);
				s[i+2] = 'x';
			} 
		}
		for(int i=0; i+2<s.length(); i++) {
			if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
				v.push_back(i+1);
				s[i+1] = 'x';
			} 
			if(s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
				v.push_back(i+1);
				s[i+1] = 'x';
			} 
		}
		cout << v.size() << endl;
		for(int i:v) cout << i+1 << ' ';
		cout << endl;
	}
}