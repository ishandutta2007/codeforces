#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
    #define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;

	string s;
	cin >> s;
	int a = -1, b = -1, c = -1, d = -1;
	for(int i=0;i<s.size();i++)
		if(s[i] == '[') {
			a = i;
			break;
		}
		for(int i=0;i<s.size();i++)
			if(s[i] == ']')
				b = i;
		if(a == -1 || b == -1) {
			cout << -1 << endl;
			return 0;
		}
		for(int i=a;i<=b;i++) {
			if(s[i] == ':') {
				if(c == -1) c = i;
				d = i;
			}
		}
	if(c == d) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for(int i=c;i<=d;i++)
		if(s[i] == '|')
			ans++;
	cout << ans + 4 << endl;	
}