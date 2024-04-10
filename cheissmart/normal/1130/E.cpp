#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int k, n=2000;
	cin >> k;
	cout << n << endl;
	cout << -1 << " ";
	int s = n+k;
	for(int i=0;i<n-1;i++) {
		int d = min(1000000, s);
		cout << d << " ";
		s -= d;
	}
}