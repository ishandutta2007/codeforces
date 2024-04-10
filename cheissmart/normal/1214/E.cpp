#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

pi d[200005];
int bk[200005], bkk[200005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> d[i].F;
		d[i].S = i*2-1;
	}
	sort(d+1, d+n+1);
	reverse(d+1, d+n+1);
	for(int i=1;i<n;i++) {
		cout << d[i].S << " " << d[i+1].S << endl;
		bk[d[i+1].S] = d[i].S;
		bkk[d[i].S] = d[i+1].S;
	}
	int c = d[n].S, dd = n, j = n, rev = 0;
	for(int i=1;i<=n;i++) {
		while(dd > d[i].F) {
			if(c & 1) j--;
			if(rev)
				c = bkk[c];
			else
				c = bk[c];
			dd--;
		}
		cout << c << " " << d[i].S+1 << endl;
		bk[d[i].S+1] = bkk[d[i].S+1] = c;
		c = d[i].S+1;
		if(i < n)
			bk[d[i].S] = d[i+1].S;
		if(j == i)
			rev = 1;
		if(rev) dd += 2;
	}
}