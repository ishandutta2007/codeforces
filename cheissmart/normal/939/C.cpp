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

int a[200005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		a[i+n] = a[i];
	}
	for(int i=1;i<=n*2;i++)
		a[i] += a[i-1];
	int s, f, mx = -1, mxi;
	cin >> s >> f;
	for(int i=1;i<=n;i++) {
		int j = f-i, k = s-i;
		j = (j-1+n)%n+1;
		k = (k-1+n)%n+1;
		if(k > j) j += n;
		int cans = a[j] - a[k];
		if(cans > mx) {
			mx = cans;
			mxi = i;
		}
	}
	cout << mxi << endl;
	
}