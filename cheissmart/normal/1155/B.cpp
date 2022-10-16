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
	int d = n - 11, r = d / 2, ct = 0;
	for(char c:s)
		ct += c == '8';
	if(ct <= r) {
		cout << "NO" << endl;
		return 0;
	}
	int i, j;
	for(i=0, j=0;i<n&&j<r+1;i++) {
		if(s[i] == '8') 
			j++;
	}
	if(i - 1 - r <= r) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}