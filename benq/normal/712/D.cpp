#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
const int MOD = 1000000007;

ll rec[101][200001]; 

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b,k,t; cin >> a >> b >> k >> t;
	F0R(i,200001) rec[0][i] = 1;
	FOR(i,1,t+1)
		F0R(z,200001) {
			if (z != 0) rec[i][z] = rec[i][z-1];
			rec[i][z] += rec[i-1][z];
			if (z >= 2*k+1) rec[i][z] -= rec[i-1][z-2*k-1];
			rec[i][z] %= MOD;
			while (rec[i][z]<0) rec[i][z] += MOD;
		}
	ll ans = 0;
	F0R(i,2*k*t+1) {
		int z = i+a-b-1;
		if (z < 0) continue;
		z = min(z,2*k*t);
		if (i == 0) ans += rec[t][i]*rec[t][z];
		else ans += (rec[t][i]-rec[t][i-1])*rec[t][z];
		ans %= MOD;
		while (ans<0) ans += MOD;
	}
	cout << ans;
}