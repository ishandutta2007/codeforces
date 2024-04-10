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

int main()
{
	IO_OP;
	
	int n, x, a[3] = {0, 1, 2};
	cin >> n >> x;
	n %= 6;
	for(int i=0;i<n;i++) {
		if(i&1) swap(a[1], a[2]);
		else swap(a[0], a[1]);
	}
	cout << a[x] << endl;
	
}