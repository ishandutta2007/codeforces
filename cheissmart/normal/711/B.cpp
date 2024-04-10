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

ll a[512][512];

int main()
{
	IO_OP;
	
	int n, r, c;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			cin >> a[i][j];
			if(a[i][j] == 0)
				r = i, c = j;	
		}
	if(n == 1) {
		cout << 87 << endl;
		return 0;
	}
	else{
		int tr = 1;
		ll sm1 = 0, sm2 = 0;
		if(r) tr =  r-1;
		for(int i=0;i<n;i++)
			sm1 += a[r][i], sm2 += a[tr][i];
		if(sm1 >= sm2) {
			cout << -1 << endl;
			return 0;
		}
		a[r][c] = sm2 - sm1;
		for(int i=0;i<n;i++) {
			ll smr = 0, smc = 0;
			for(int j=0;j<n;j++) 
				smr += a[i][j], smc += a[j][i];
			if(smr != sm2 || smc != sm2) {
				cout << -1 << endl;
				return 0;
			}
		}
		ll smd1 = 0, smd2 = 0;
		for(int i=0;i<n;i++) {
			smd1 += a[i][i];
			smd2 += a[i][n-i-1];
		}
		if(smd1 != sm2 || smd2 != sm2) {
			cout << -1 << endl;
			return 0;
		}
		cout << a[r][c] << endl;
	}
}