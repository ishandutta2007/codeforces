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
	int ct1 = 0, ct2 = 0;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t > 0)
			ct1++;
		else if(t < 0)
			ct2++;
	}
	if(ct1 >= (n+1)/2) {
		cout << 1 << endl;
	} else if(ct2 >= (n+1)/2) {
		cout << -1 << endl;
	} else {
		cout << 0 << endl;
	}
}