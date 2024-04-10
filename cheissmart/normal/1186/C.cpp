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
	
	string a, b;
	cin >> a >> b;
	int y = 0, x = 0;
	for(int i=0;i<b.size();i++)
		if(b[i] == '1')
			y++;
	for(int i=0;i<b.size();i++) {
		if(a[i] == '1')
			x++;
	}
	int ans = 0;
	if((x+y) % 2 == 0)
		ans++;
	for(int i=1;i<=a.size()-b.size();i++) {
		if(a[i-1] == '1')
			x--;
		if(a[i+b.size()-1] == '1')
			x++;
		if((x+y) % 2 == 0)
			ans++;
	}
	
	cout << ans << endl;
}