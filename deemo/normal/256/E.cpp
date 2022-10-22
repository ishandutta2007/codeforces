#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MOD = 777777777;
const int MAXN = 77777 + 100;

int n, q, val[MAXN];
ll d[5][5][MAXN + 2], weed[4 * MAXN];
bool good[6][6];
set<int>	st;

void init(){
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			d[i][j][0] = good[i][j];
	
	for (int i = 1; i < MAXN; i++)
		for (int a = 1; a <= 4; a++)
			for (int b = 1; b <= 4; b++)
				for (int x = 1; x <= 3; x++)
					if (good[a][x])
						d[a][b][i] = (d[a][b][i] + d[x][b][i - 1]) % MOD;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		if (!b)
			weed[v] = d[4][4][n - 2];
		else
			weed[v] = 1;
		return;
	}

	int mid = b+e>>1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = weed[v<<1] * weed[v<<1^1] % MOD;
}

void water(int v, int b, int e, int pos, ll val){
	if (e - b == 1){
		weed[v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	if (pos < mid)
		water(v<<1, b, mid, pos, val);
	else
		water(v<<1^1, mid, e, pos, val);
	weed[v] = weed[v<<1] * weed[v<<1^1] % MOD;
}

void burn(int v){
	val[v] = 0;
	auto it = st.upper_bound(v);
	int nxt = *it;
	it--;	it--;
	int prv = *it;

	water(1, 0, n, v, 1);
	water(1, 0, n, prv, d[val[prv]][val[nxt]][nxt - prv - 1]);
	st.erase(v);
}

void grow(int v, int x){
	val[v] = x;
	auto it = st.upper_bound(v);
	int nxt = *it;
	it--;
	int prv = *it;

	water(1, 0, n, v, d[val[v]][val[nxt]][nxt - v - 1]);
	water(1, 0, n, prv, d[val[prv]][val[v]][v - prv - 1]);
	
	st.insert(v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;	n += 2;	//1 -> n - 2
	val[0] = val[n - 1] = 4;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			if (max(i, j) == 4)	good[i][j] = 1;
			else	cin >> good[i][j];
	init();
	plant(1, 0, n);
	st.insert(0);
	st.insert(n-1);
	while (q--){
		int v, x;	cin >> v >> x;
		if (val[v] ^ x){
			if (val[v])
				burn(v);
			if (x)
				grow(v, x);
		}
		cout << weed[1] << "\n";
	}
	return 0;
}