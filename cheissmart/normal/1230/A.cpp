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
	
	int a[4], s = 0;
	for(int i=0;i<4;i++)
		cin >> a[i], s += a[i];
	if(s & 1) return cout << "NO" << endl, 0;
	s /= 2;
	bool ok = false;
	for(int i=0;i<4;i++) {
		if(a[i] == s) ok = true;
		for(int j=i+1;j<4;j++){
			if(a[i] + a[j] == s) ok = true;
			for(int k=j+1;k<4;k++){
				if(a[i] + a[j] + a[k] == s)
					ok =true;
			}
		}
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
		
}