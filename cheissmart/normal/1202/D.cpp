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
	
	int t;
	cin >> t;
	while(t--) {
		int n,i;
		cin >> n;
		for(i=2;1LL*i*(i-1)/2 <= n;i++);
		i--;
		cout << 1;
		cout << 33;
		for(int j=0;j<n-i*(i-1)/2;j++)
			cout << 7;
		for(int j=2;j<i;j++)
			cout << 3;
		cout << 7 << endl;
	}

}