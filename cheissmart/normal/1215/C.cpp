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

int32_t main()
{
	IO_OP;
	
	int n, a = 0, b = 0;
	string s, t;
	cin >> n >> s >> t;
	for(char c:s) if(c == 'a') a++; else b++;
	for(char c:t) if(c == 'a') a++; else b++;
	if(a%2 || b%2) {
		cout << -1 << endl;
		return 0;
	}
	vi x, y;
	for(int i=0;i<n;i++)
		if(s[i] == 'a' && t[i] == 'b')
			x.PB(i+1);
		else if(s[i] == 'b' && t[i] == 'a')
			y.PB(i+1);
	int k = x.size() / 2 + y.size() / 2 + x.size() % 2 + y.size() % 2;
	cout << k << endl;
	for(int i=0;i+1<x.size();i+=2)
		cout << x[i] << " " << x[i+1] << endl;
	for(int i=0;i+1<y.size();i+=2)
		cout << y[i] << " " << y[i+1] << endl;
	if(x.size()&1) {
		cout << x.back() << " " << x.back() << endl;
		cout << x.back() << " " << y.back() << endl;
	}
}