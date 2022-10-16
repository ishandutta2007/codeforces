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

int a[105];

int main()
{
	IO_OP;
	vi v;
	
	int n, s = 0, t = 0;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		t += a[i];
		if(i == 1) {
			s += a[i];
			v.PB(i);
		} else {
			if(a[i]*2 <= a[1]) {
				s += a[i];
				v.PB(i);
			}
		}
	}
	if(s > t/2) {
		cout << v.size() << endl;
		for(int e:v)
			cout << e << " ";
	} else {
		cout << 0 << endl;
	}
	
}