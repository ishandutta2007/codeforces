#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

//point update, range query, 0-indexed
struct bit {
	vector<int> b;
	bit(int n=0):b(n+1){};
	inline void update(int i, int v){for(++i;i<b.size();b[i]+=v,i+=i&-i);}
	int prefix(int i) const {return i?b[i]+prefix(i^(i&-i)):0;}
	inline int query(int l, int r) const {return prefix(r+1)-prefix(l);}
};

//mod, class, letter
string s;
bit B[11][10][4];

int ch(char c) {
	if(c=='A') return 0;
	if(c=='C') return 1;
	if(c=='T') return 2;
	if(c=='G') return 3;
	return -1000;
}

void update_char(int i, char c, bool b=true) {
	for(int m = 1; m <= 10; ++m) {
		if(b)
			B[m][i%m][ch(s[i])].update(i,-1);
		B[m][i%m][ch(c)].update(i,1);
	}
	s[i] = c;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> s;
	for(int m = 1; m <= 10; ++m) {
		for(int c = 0; c < m; ++c) {
			for(int l = 0; l < 4; ++l) {
				B[m][c][l] = bit(s.size());
			}
		}
	}
	for(int i = 0; i < s.size(); ++i)
		update_char(i,s[i],false);
	int q;
	cin >> q;
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int x;
			string c;
			cin >> x >> c,--x;
			update_char(x,c[0]);
		} else {
			int l,r;
			string e;
			cin >> l >> r >> e,--l,--r;
			int ans = 0, m = e.size();
			for(int i = 0; i < e.size(); ++i) {
				//how many match e[i] and are cong with l+i mod m
				// cout
				int md = (l+i)%m;
				ans += B[m][md][ch(e[i])].query(l,r);
			}
			cout << ans << "\n";
		}
	}

}