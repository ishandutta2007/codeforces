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

int a[100005], c[100005], cc[100005];

int main()
{
	IO_OP;
	
	int n, ans = 0, m = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++) {
		cc[c[a[i]]]--;
		c[a[i]]++;
		m = max(c[a[i]], m);
		cc[c[a[i]]]++;
		if((cc[m] == 1 && cc[m-1]*(m-1)+m == i+1) || (cc[1] == 1 && cc[m] * m == i) || cc[1] == i + 1)
			ans = max(ans, i+1);
	}
	cout << ans << endl;
}