#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int prefix[4005], ct[40005];

int pre(int x) {
	if(x < 0) return 0;
	return prefix[x];
}

int sm(int i, int j) {
	return pre(j) - pre(i-1);
}

signed main()
{
	IO_OP;
	
	int a, ans = 0, n;
	string s;
	cin >> a >> s;
	prefix[0] = s[0] - '0';
	n = s.size();
	for(int i=1;i<n;i++)
		prefix[i] = prefix[i-1] + s[i] - '0';
	if(a == 0) {
		int ans1 = 0;
		for(int i=0;i<n;++i)
			for(int j=i;j<n;++j) 
				if(sm(i, j) == 0)
					ans1++;
		cout << ans1*n*(n+1)-ans1*ans1 << endl;
		return 0;
	}
	for(int i=0;i<n;++i)
		for(int j=i;j<n;++j)
			++ct[sm(i, j)];
	for(int i=0;i<n;++i) {
		for(int j=i;j<n;++j) {
			if(sm(i, j) == 0 || a % sm(i, j)) continue;
			int p = a / sm(i, j);
			if(p < 40005)
				ans += ct[p];
		}
	}
	cout << ans << endl;
}