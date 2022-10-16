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

int a[200005], cnt[200005];

signed main()
{
	IO_OP;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int num = 200005;
	for(int i=0;i<200005;i++)
		if(cnt[i] > cnt[num])
			num = i;

	int j;
	for(j=0;j<n;j++)
		if(a[j] == num) break;
	V<pair<pi ,int>> v;
	for(int i=j-1;i>=0;i--) {
		if(a[i] > num) {
			v.PB({{i, i+1}, 2});
		} else if(a[i] < num) {
			v.PB({{i, i+1}, 1});
		}
	}
	for(int i=j+1;i<n;i++) {
		if(a[i] > num) {
			v.PB({{i, i-1}, 2});
		} else if(a[i] < num) {
			v.PB({{i, i-1}, 1});
		}
	}
	cout << v.size() << endl;
	for(auto op:v) 
		cout << op.S << " " << op.F.F+1 << " " << op.F.S+1 << endl;
}