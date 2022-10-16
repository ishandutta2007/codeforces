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
	
	int k, ans = 0, sm = 0;
	string s;
	cin >> k >> s;
	sort(s.begin(), s.end());
	for(char c:s)
		sm += c - '0';
	for(int i=0;sm < k;i++) {
		sm += 9-(s[i]-'0');
		ans++;
	}
	cout << ans << endl;
}