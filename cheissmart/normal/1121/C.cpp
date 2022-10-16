#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[1024], b[1024];
bool ok[1024];
int main()
{
    IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int tp = 0;
	set<int> p;
	int q = 0, m = 0;
	for(int t=0;p.size()||tp<n;t++) {
		while (p.size() < k && tp < n)
			p.insert(tp++);
		for (auto it = p.begin(); it != p.end();) {
			int x = *it;
			if (++b[x] == a[x])
				p.erase(it++), m++;
			else
				it++;
			ok[x] |= b[x] == q;
		}
		q = 100.*m/n+0.5;
	}
	int ans = 0;
	for(int i=0;i<n;i++)
		ans += ok[i];
	cout << ans << endl;
}