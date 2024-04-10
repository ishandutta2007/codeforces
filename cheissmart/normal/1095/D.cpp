#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[200005][2];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i][0] >> a[i][1];
	}
	if(n == 3) {
		cout << "1 2 3" << endl;
		return 0;
	}
	vi v;
	v.PB(1);
	for(int i=0;i<n;i++) {
		int c = v.back();
		int l = a[c][0], r = a[c][1];
		if(a[l][0] == r || a[l][1] == r) {
			v.PB(l);
			v.PB(r);
		} else {
			v.PB(r);
			v.PB(l);
		}
	}
	for(int i=0;i<n;i++)
		cout << v[i] << " ";
}