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
	
	int n, x = 0, y = 0,ans = 0;
	bool l;
	string s;
	cin >> n >> s;
	if(s[0] == 'U') y++;
	else x++;
	if(x > y) l = 0;
	else if(x < y) l = 1;
	for(int i=1;i<n;i++) {
		char c = s[i];
		if(c == 'U') y++;
		else x++;
		bool ll = l;
		if(x > y) ll = 0;
		else if(x < y) ll = 1;
		if(l != ll)
			ans++;
		l = ll;
	}
	cout << ans << endl;
}