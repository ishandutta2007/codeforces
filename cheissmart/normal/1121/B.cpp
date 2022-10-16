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

int a[1003], m[200005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi s;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i != j)
				m[a[i]+a[j]]++;
	int mx = 0;
	for(int i=0;i<200005;i++)
		mx = max(mx, m[i]);
	cout << mx/2 << endl;
}