#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define real lasidhfuih

const int MAXN = 1e5 + 10;
const int MAXVAL = 7000 + 10;

int n, q;
bitset<MAXVAL> ans[MAXN], sv[MAXVAL], tt[MAXVAL], temp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < MAXVAL; i++)
		for (int j = i; j < MAXVAL; j += i)
			sv[j][i] = 1;
	for (int i = MAXVAL-1; i; i--){
		tt[i][i] = 1;
		for (int j = i+i; j < MAXVAL; j += i)
			tt[i] ^= tt[j];
	}

	cin >> n >> q;
	while (q--){
		int t; cin >> t;
		if (t == 4){
			int x, v; cin >> x >> v, x--;
			temp = ans[x]&tt[v];
			cout << (temp.count()&1);
		}
		else if (t == 2){
			int x, y, z; cin >> x >> y >> z, x--, y--, z--;
			ans[x] = ans[y]^ans[z];
		}
		else if (t == 3){
			int x, y, z; cin >> x >> y >> z, x--, y--, z--;
			ans[x] = ans[y]&ans[z];
		}
		else{//t == 1
			int x, v; cin >> x >> v, x--;
			ans[x] = sv[v];
		}
	}
	cout << "\n";
	return 0;
}