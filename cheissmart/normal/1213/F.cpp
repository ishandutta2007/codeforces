#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int p[200005], q[200005];

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		cin >> p[i];
		p[i]--;
	}
	for(int i=0;i<n;i++) {
		cin >> q[i];
		q[i]--;
	}
	set<int> s, t;
	vi v;
	for(int i=0;i<n;i++) {
		if(t.count(p[i])) {
			t.erase(p[i]);
		} else {
			s.insert(p[i]);
		}
		if(s.count(q[i])) {
			s.erase(q[i]);
		} else {
			t.insert(q[i]);
		}
		if(s.empty() && t.empty()) {
			v.PB(i);
		}
	}
	if(v.size() < k) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		int l = 0, r;
		string ans(n, ' ');
		for(int i=0;i<v.size();i++) {
			r = v[i];
			char c = 'a' + min(i,25);
			for(int j=l;j<=r;j++)
				ans[p[j]] = c;
			l = r + 1;
		}
		cout << ans << endl;
	}


}