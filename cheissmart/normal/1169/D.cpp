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

string s;

bool ok(int i, int j) {
	if(j >= s.size()) return false;
	for(int k=1;k<=(j-i)/2;k++) {
		if(s[j] == s[j-k] && s[j-k] == s[j-k-k])
			return false;
	}
	return true;
}

int main()
{
	IO_OP;
	
	cin >> s;
	ll ct = 0;
	for(int i=0, j=0;i<s.size();i++) {
		while(ok(i, j))
			j++;
		j--;
		ct += j - i + 1;
	}
	ll ans = 1ll * s.size() * (s.size()+1) / 2;
	ans -= ct;
	cout << ans << endl;
	
}