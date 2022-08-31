#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i=0; i<a; i++)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)

int nex[30000000][2], co[30000000], ne = 0;
long long ans = 0;

void ins(int num) {
	int cur = 0;
	F0Rd(i,30) {
		int temp = (num>>i) & 1;
		if (!nex[cur][temp]) nex[cur][temp] = ++ne; 
		cur = nex[cur][temp];
		co[cur] ++;
	}
}

int query(int ind, int num, int low, int cur) {
	int bit = (num>>cur) & 1;
	if ((1<<cur) >= low) {
		int temp = 0;
		if (nex[ind][1-bit] != 0) temp = co[nex[ind][1-bit]];
		if (nex[ind][bit] != 0) temp += query(nex[ind][bit],num,low,cur-1);
		return temp;
	} else if (nex[ind][1-bit]) return query(nex[ind][1-bit],num,low^(1<<cur),cur-1);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k, z = 0; cin >> n >> k; 
	ins(0);
	F0R(i,n) {
		int t; cin >> t; z ^= t;
		ans += query(0,z,k,29);
		ins(z);
	}
	cout << ans;
}