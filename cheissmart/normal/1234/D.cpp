#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

struct{
	int bit[100005]; // [1, n]
	int lowbit(int x) {
		return x & -x;
	}

	void add(int i, int d) {
		while(i < 100005) {
			bit[i] += d;
			i += lowbit(i);
		}
	}
	int qry(int i) {
		int res = 0;
		while(i) {
			res += bit[i];
			i -= lowbit(i);
		}
		return res;
	}

}tt[30];

int32_t main()
{
	IO_OP;
	
	string s;
	int q;
	cin >> s >> q;
	for(int pos=0;pos<s.size();pos++) {
		char c = s[pos];
		int t = c - 'a';
		tt[t].add(pos+1, 1);
	}
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int pos, t, r;
			char c;
			cin >> pos >> c;
			pos--, t = c - 'a', r = s[pos] - 'a';
			s[pos] = c;
			tt[r].add(pos+1, -1);
			tt[t].add(pos+1, 1);
		} else {
			int l, r, ans = 0;
			cin >> l >> r;
			for(int i=0;i<26;i++) {
				if(tt[i].qry(r)-tt[i].qry(l-1))
					ans++;
			}
			cout << ans << endl;
		}
	}
	
}