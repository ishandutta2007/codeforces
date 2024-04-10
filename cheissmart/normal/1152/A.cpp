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

int main()
{
	IO_OP;
	
	int n, m, a = 0, b = 0, c = 0, d = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t & 1) a++;
		else b++;
	}
	
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		if(t & 1) c++;
		else d++;
	}
	cout << min(a, d) + min(b, c) << endl;
	
}