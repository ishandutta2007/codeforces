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
	
	int n;
	cin >> n;
	int mx1 = -1, mx2 = -1;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t <= 500000) {
			mx1 = max(mx1, t-1);
		} else {
			mx2 = max(mx2, 1000000-t);
		}
	}
	cout << max(mx1, mx2) << endl; 
}