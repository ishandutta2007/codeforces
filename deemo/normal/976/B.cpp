#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, k; cin >> n >> m >> k;
	if (k < n-1)
		cout << k+1 << " 1\n";
	else{
		k -= n-1;
		if (k == 1)
			cout << n << " 2\n";
		else{
			k--;
			ll row = n, col = 2;
			row -= (k/(2ll*(m-1)))*2;
			k %= 2ll*(m-1);
			if (k <= m-2)
				col += k;
			else{
				col += m-2;
				k-= m-2;
				if (k == 1)
					row--;
				else{
					row--;
					k--;
					if (k <= m-2)
						col -= k;
					else{
						col -= m-2;
						row--;
					}
				}
			}
			cout << row << " " << col << endl;
		}
	}
	return 0;
}