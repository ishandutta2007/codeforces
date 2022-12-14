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

int p[505], pmn[505], smn[505];
int n;
string s;

int go() {
	for(int i=1;i<=n;i++)
		if(s[i] == '(') p[i] = p[i-1] + 1;
		else p[i] = p[i-1] - 1;
	pmn[1] = p[1];
	for(int i=2;i<=n;i++) pmn[i] = min(pmn[i-1], p[i]);
	smn[n] = p[n];
	for(int i=n-1;i>=1;i--) smn[i] = min(smn[i+1], p[i]);
	int ret = 0;
	if(pmn[n] >= 0) ret++;
	for(int i=2;i<=n;i++) {
		int d = p[i-1];
		if(smn[i]-d >= 0) {
			int r = p[n] - d;
			if(r + pmn[i-1] >= 0) ret++;
		}
	}
	return ret;
}

int32_t main()
{
	IO_OP;
	
	cin >> n >> s;
	s = ' ' + s;
	for(int i=1;i<=n;i++)
		if(s[i] == '(') p[i] = p[i-1] + 1;
		else p[i] = p[i-1] - 1;
	if(p[n] != 0) {
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	int mx = go(), l = 1, r = 1;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(s[i] == s[j]) continue;
			swap(s[i], s[j]);
			int cans = go();
			if(cans > mx)
				mx = cans, l = i, r = j;
			swap(s[i], s[j]);
		}
	}
	cout << mx << endl;
	cout << l << " " << r << endl;
}