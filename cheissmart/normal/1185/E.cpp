#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

char a[2003][2003];
int mxr[256], mxc[256], mnr[256], mnc[256];

bool solve() {
	int n, m;
	cin >> n >> m;
	memset(mnr, 0x3f, sizeof mnr);
	memset(mnc, 0x3f, sizeof mnc);
	memset(mxr, 0, sizeof mxr);
	memset(mxc, 0, sizeof mxc);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin >> a[i][j];
			mxr[a[i][j]] = max(mxr[a[i][j]], i);
			mxc[a[i][j]] = max(mxc[a[i][j]], j);
			mnr[a[i][j]] = min(mnr[a[i][j]], i);
			mnc[a[i][j]] = min(mnc[a[i][j]], j);
		}
	}
	vector<pair<pi, pi>> v;
	bool lose = 1;
	int x, y;
	for(char c='z';c>='a';c--) {
		if(mxr[c] == 0) {
			if(!lose)
				v.PB({{x, y}, {x, y}});
			continue;
		}
		lose = 0;
		if(mxr[c] != mnr[c] && mnc[c] != mxc[c])
			return false;
		if(mxr[c] == mnr[c]) {
			int i = mnr[c];
			for(int j=mnc[c];j<=mxc[c];j++) {
				if(a[i][j] != c && a[i][j] != '?')
					return false;
				a[i][j] = '?';
			}
		} else {
			int j = mnc[c];
			for(int i=mnr[c];i<=mxr[c];i++) {
				if(a[i][j] != c && a[i][j] != '?')
					return false;
				a[i][j] = '?';
			}
		}
		x = mnr[c], y = mnc[c];
		v.PB({{mnr[c], mnc[c]}, {mxr[c], mxc[c]}});
	}
	cout << "YES" << endl;
	cout << v.size() << endl;
	while(v.size()) {
		cout << v.back().F.F << " " << v.back().F.S << " " << v.back().S.F << " " << v.back().S.S << endl;
		v.pop_back();
	}
	return true;	
}

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--)
		if(!solve())
			cout << "NO" << endl;
	
}