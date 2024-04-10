#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[200005];	

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	string s;
	cin >> s;
	int j = 0;
	int ans = 0;
	for(int i=0,j;i<s.size();i=j) {
		for (j=i;s[j]==s[i];j++);
		sort(a+i, a+j);
		for(int l=0;l<k&&j-l-1>=i;++l)
			ans += a[j-l-1];
	}
	cout << ans << endl;
	
}