#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;
	
	int t, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int b = n/k;
		string s = "";
		for(int i=0;i<k;i++) {
			for(int j=0;j<b;j++) {
				cout << (char)('a'+i);
			}
		}
		for(int i=0;i<n%k;i++)
			cout << 'a';
		cout << endl;
	}
}