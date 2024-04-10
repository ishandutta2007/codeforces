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
	
	int n;
	string s;
	cin >> n >> s;
	for(int i=0;i<n-1;i++) {
		if(s[i] > s[i+1]) {
			cout << "YES" << endl;
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
}