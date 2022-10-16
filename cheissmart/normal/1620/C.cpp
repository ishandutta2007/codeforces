#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;
const ll oo = 1e18 + 7;

void solve() {
	int n, k;
	ll x;
	string s;
	cin >> n >> k >> x >> s;
	
	string t;
	vi stars;
	for(char c:s) {
		if(c == 'a') t += c;
		else {
			if(t.size() && t.back() == '*') 
				stars.back()++;
			else {
				t += c;
				stars.PB(1);
			}
		}
	}
	s = t;
	int cnt = SZ(stars);
	
	reverse(ALL(stars));
	
	V<ll> aux;
	ll ways = 1;
	aux.PB(ways);
	for(int i = 0; i < cnt - 1; i++) {
		int b = k * stars[i] + 1;
		if(ways > oo / b + 1) ways = oo;
		else ways *= b;
		aux.PB(ways);
	}
	reverse(ALL(aux));
	vi len;
	for(int i = 0; i < cnt; i++) {
		for(int j = 0; ; j++) {
			if(x <= aux[i]) {
				len.PB(j);
				break;
			} else {
				x -= aux[i];
			}
		}
	}
	reverse(ALL(len));
	for(char c:s) {
		if(c == '*') {
			assert(len.size());
			cout << string(len.back(), 'b');
			len.pop_back();
		} else cout << c;
	}
	cout << '\n';
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--)
		solve();	
	
}