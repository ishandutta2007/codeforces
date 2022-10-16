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
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		int i = 0, j = n-1;
		int l = 0, r = 0;
		for(char c:s)
			if(c == '>') l++;
			else r++;
		if(l == 0 || r == 0) {
			cout << 0 << endl;
			continue;
		}
		while(s[i] == '<') i++;
		while(s[j] == '>') j--;
		cout << min(i, n-j-1) << endl;
	}
	
}