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

int p[400005], s[400005];

int main()
{
	IO_OP;

	int n, I;
	cin >> n >> I;
	map<int, int> m;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		m[t]++;
	}
	I *= 8, I /= n;
	if(I >= 20) {
		cout << 0 << endl;
		return 0;
	}
	I = 1 << I;
	vector<pi> v(1);
	for(pi p:m)
		v.PB(p);
	for(int i=1;i<v.size();i++)
		p[i] = p[i-1] + v[i].S;
	for(int i=v.size()-1;i>0;i--)
		s[i] = s[i+1] + v[i].S;
	int ans = INF;
	// cout << I << endl;
	for(int i=1;i<v.size();i++)
		ans = min(ans, p[i-1]+s[i+I]);
	cout << ans << endl;
}