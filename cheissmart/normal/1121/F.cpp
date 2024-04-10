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

int dp[5003], z[5003];

int main()
{
	IO_OP;
	
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	dp[0] = a;
	for(int i=1;i<n;i++) {
		dp[i] = a + dp[i - 1];
		z[i] = 0;
		for(int j=i-1,l=i,r=i;j>=0;j--) {
			if(j >= l) z[j] = min(j-l+1, z[i-r+j]);
			else z[j] = 0;
			while(j-z[j] >= 0 && s[i-z[j]] == s[j-z[j]])
				z[j]++;
			if(j-z[j]+1 < l) 
				l = j-z[j]+1, r = j;
			int zz = min(z[j], i-j);
			if(zz) {
				int p = i - zz;
				// cout << s.substr(p+1, zz) << " " << s.substr(j-zz+1, zz) << endl;
				// assert(s.substr(p+1, zz) == s.substr(j-zz+1, zz));
				// cout << "i: " << i << ", " << "z[" << j << "] = " << zz << " " << p << endl; 
				dp[i] = min(dp[i], dp[p] + b);
			}
 		}
 	}
 	cout << dp[n-1] << endl;
	
}