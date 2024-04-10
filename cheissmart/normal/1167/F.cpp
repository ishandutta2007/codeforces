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

const int M = 1e9 + 7;
#define MAXN 500005
struct BIT
{
	ll bit[MAXN];
	void add(int i,int v){
		while(i < MAXN) {
			bit[i] += v;
			bit[i] %= M;
			i += i & -i;
		}
	}
	ll qry(int i) {
		ll ret = 0;
		while(i) {
			ret += bit[i];
			ret %= M;
			i -= i & -i;
		}
		return ret;
	}
	ll qry(int i,int j) {
		return (qry(j) - qry(i-1) + M) % M;
	}
} b1, b2;
int a[500005];
pi b[500005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		b[i] = {a[i], i};
	}
	sort(b+1, b+n+1);
	ll ans = 0;
	for(int i=1;i<=n;i++) {
		ll j = b[i].S;
		ll tmp = j * (n+1-j) % M;
		tmp += b1.qry(j) * (n+1-j) % M;
		tmp += b2.qry(j, n) * j % M;
		ans += tmp * b[i].F % M;
		b1.add(j,j);
		b2.add(j,n+1-j);
	}
	cout << ans % M << endl;
}