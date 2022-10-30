#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string s,t;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m >> s >> t;
	int bn = 0x7fffffff,bi = -1;
	for(int i = 0; i+s.size() <= t.size(); ++i) {
		int df = 0;
		for(int j = 0; j < s.size(); ++j) {
			df += s[j]!=t[i+j];
		}
		// cout << bn << endl;
		if(df < bn) bn = df, bi = i;
	}
	cout << bn << "\n";
	for(int j = 0; j < s.size(); ++j) {
		if(s[j]!=t[bi+j]) {
			cout << j+1 << " ";
		}
	}
	cout << "\n";
}