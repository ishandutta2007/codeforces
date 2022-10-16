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

int a[100005], isint[100005];

int main()
{
	IO_OP;
	
	int s = 0, n;
	cin >> n;
	for(int i=0;i<n;i++) {
		double f;
		cin >> f;
		a[i] = min(floor(f), ceil(f));
		if(floor(f) == ceil(f)) isint[i] = 1;
		s += a[i];
	}
	for(int i=0;i<n;i++) {
		if(isint[i]) {
			cout << a[i] << endl;
			continue;
		}
		if(s < 0) {
			cout << a[i]+1 << endl;
			s++;
		} else {
			cout << a[i] << endl;
		}
	}
}