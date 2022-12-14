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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int p[400005], n;

bool solve() {
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> p[i];
	vi v;
	for(int i=0;i<n;) {
		int j = i;
		while(i < n && p[i] == p[j]) i++;
		v.PB(i - j);
	}
	int totake = (n+1)/2, take = 0;
	while(take < totake) {
		take += v.back();
		v.pop_back();
	}
	if(v.size() < 3) return false;
	int rem = n - take, cnt = 0, s=-1, b=0;
	int g = v[0];
	rem -= g;
	for(int i=1;i<(int)v.size()-1;i++) {
		cnt += v[i];
		if(cnt > g && rem - cnt > g) {
			s = cnt, b = rem - cnt;
			break;
		}
	}
	if(s == -1) return false;
	cout << g << " " << s << " " << b << "\n";
	return true;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		if(!solve()) {
			cout << "0 0 0\n";
		}
	}
		
}