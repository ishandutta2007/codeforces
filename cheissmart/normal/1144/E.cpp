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

signed main()
{
	IO_OP;
	
	int k;
	string s, t;
	cin >> k >> s >> t;
	vi a, b;
	for(int i=0;i<k;i++) a.PB(s[i] - 'a');
	for(int i=0;i<k;i++) b.PB(t[i] - 'a');
	reverse(ALL(a)), reverse(ALL(b));
	a.PB(0);
	for(int i=0;i<k;i++) {
		a[i] += b[i];
		if(a[i] >= 26) {
			a[i] -= 26;
			a[i+1]++;
		}
	}
	reverse(ALL(a));
	vi u(a.size());
	for(int i=0;i<a.size();i++) {
		u[i] = a[i] / 2;
		if(a[i] & 1) a[i+1] += 26;
	}
	for(int i=1;i<=k;i++)
		cout << (char)(u[i]+'a');

}