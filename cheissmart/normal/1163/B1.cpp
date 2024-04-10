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

int a[100005], c[11];

int main()
{
	IO_OP;
	
	int n, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++) {
		c[a[i]]++;
		bool ok = 0;
		for(int j=1;j<=10;j++) {
			bool ook = 1;
			if(c[j] == 0) continue;
			c[j]--;
			int l;
			for(int k=1;k<=10;k++)
				if(c[k]) l = k;
			for(int k=1;k<=10;k++)
				if(c[k] && c[k] != c[l])
					ook = 0;
			c[j]++;
			if(ook) ok = 1;	
		}
		if(ok)
			ans = max(ans, i+1);
	}
	cout << ans << endl;
}