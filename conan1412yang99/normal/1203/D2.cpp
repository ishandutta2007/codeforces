#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int p[200005], q[200005];

int32_t main() {
	

	string s, t;
	cin >> s >> t;
	for(int i=0, j=0;i<s.size();i++) {
		if(s[i] == t[j]) {
			p[j] = i;
			j++;
		}
	}
	for(int i=s.size()-1, j=t.size()-1;i>=0;i--) {
		if(s[i] == t[j]) {
			q[j] = i;
			j--;
		}
	}
	int ans = max((int)s.size() - p[t.size()-1]-1, q[0]);
	for(int i=0;i<t.size()-1;i++) {
		ans = max(q[i+1]-p[i]-1, ans);
	}
	cout << ans << endl;

	return 0;
}