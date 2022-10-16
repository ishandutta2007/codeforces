#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 1e5+5;

int p[N], v[N], t[N], a[N], tp[N];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> v[i];
	for(int i=1;i<=n;i++)
		cin >> t[i];	
	for(int i=1;i<=n;i++)
		tp[i] = tp[i-1] + t[i];
	for(int i=1;i<=n;i++) {
		int b = v[i] + tp[i-1];
		int j = upper_bound(tp, tp+n+1, b) - tp - 1;
		p[i]++,p[j+1]--;
		a[j+1] += b - tp[j];
	}
	for(int i=1;i<=n;i++)
		p[i] += p[i-1];
	for(int i=1;i<=n;i++) {
		cout << p[i] * t[i] + a[i] << " ";
	}
}