#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x<<": "<<x<<'\n'
#define arr_dump(x, n) {cerr<<#x<<"[]: ";for(int i=1;i<=n;++i)cerr<<x[i]<<" ";cerr<<'\n';}

int Count[5005], V[5005], Sol[5005];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> V[i];

	for(int i = 1; i <= n; ++i) {
		memset(Count,0,sizeof(Count));

		int best = 0;
		for(int j = i; j <= n; ++j) {
			int val = V[j];
			Count[val] += 1;
			if(make_pair(Count[val], -val) > make_pair(Count[best], -best))
				best = val;

			Sol[best] += 1; 
		}
	}

	for(int i = 1; i <= n; ++i)
		cout << Sol[i] << " ";
	return 0;
}