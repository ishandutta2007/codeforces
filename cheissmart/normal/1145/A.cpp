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

int a[20];

int f(int l, int r) {
	int ok = 1;
	for(int i=l+1;i<r;i++)
		if(a[i] < a[i-1])
			ok = 0;
	if(ok) return r - l;
	return max(f(l, (l+r)/2), f((l+r)/2, r));
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << f(0, n) << endl;
}