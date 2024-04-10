#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 998244353;


int32_t main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	int p = 1;
	for(int i=0;i<n+m;i++) {
		p *= 2;
		p %= M;
	}
	cout << p << endl;
}