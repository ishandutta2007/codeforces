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

signed main()
{
	IO_OP;
	
	int k;
	cin >> k;
	cout << 3 << " " << 3 << endl;
	int a[][3] = {
		{(1<<18)-1, k, 0},
		{1<<17, k, 0},
		{1<<17, (1<<18)-1, k}
	};

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
}