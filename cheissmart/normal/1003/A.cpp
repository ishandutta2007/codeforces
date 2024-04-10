#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int n;
	map<int, int> m;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >>t;
		m[t]++;
	}
	int mx = 0;
	for(pi p:m)
		mx = max(mx, p.S);
	cout << mx << endl;
	
}