#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		sort(ALL(s));
		bool ok = true;
		for(int i=0;i<s.size()-1;i++)
			if(s[i]+1 != s[i+1])
				ok = false;
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

}