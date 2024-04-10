#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[300005], b[300005], c[300005], d[300005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0,j=0;i<n;i++) {
		if(i) c[a[i-1]]--;
		while(j<n && c[a[j]] == 0) c[a[j++]]++;
		b[i] = j - 1;
	}
	d[0] = a[0];
	for(int i=1;i<n;i++)
		d[i] = d[i-1] + a[i];
	vi v({-1});
	for(int i=0;i<n;i++)
		if(a[i] == 1)
			v.PB(i);
	v.PB(n);
	int ans = 0;
	for(int i=1;i<v.size()-1;i++) {
		int r = v[i+1]-1;
		int l = v[i-1]+1;
		int mx = -87;
		for(int j=v[i];j<=r;j++) {
			mx = max(mx, a[j]);
			int k = j - mx + 1;
			if(k >= 0 && b[k] >= j && d[j] - d[k-1] == mx*(mx+1)/2)
				ans++; 
		}
		mx = -87;
		for(int j=v[i]-1;j>=l;j--) {
			mx = max(mx, a[j]);
			int k = j + mx - 1;
			if(k<n && b[j] >= k && d[k] - d[j-1] == mx*(mx+1)/2)
				ans++; 
		}
	}
	cout << ans << endl;
}