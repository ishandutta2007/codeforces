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
	
	int n, k = 0, s = 0;
	cin >> n;
	for(int i=0;i<n/2;i++) {
		char c;
		cin >> c;
		if(c == '?') k++;
		else s -= c - '0';
	}
	for(int i=0;i<n/2;i++) {
		char c;
		cin >> c;
		if(c == '?') k--;
		else s += c - '0';
	}
	if(s == 9*k/2) cout << "Bicarp" << endl;
	else cout << "Monocarp" << endl;

}