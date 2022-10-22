#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int INF = 1e8;

struct Node{
	int val[5][5];
	Node(){
		memset(val, 63, sizeof(val));
	}
};

int n, q;
string s;
Node ZZ, weed[4 * MAXN];

Node sprout(Node a, Node b){
	Node ret;
	for (int i = 0; i < 5; i++)
		for (int j = 0; i+j < 5; j++)
			for (int k = 0; k <= j; k++)
				ret.val[i][j] = min(ret.val[i][j], a.val[i][k] + b.val[i + k][j - k]);
	return ret;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		for (int w = 0; w < 5; w++)
			weed[v].val[w][0] = 1;

		if (s[b] == '2'){
			weed[v].val[0][1] = 0;
			for (int w = 1; w < 5; w++)
				weed[v].val[w][0] = 0;
		}
		else if (s[b] == '0'){
			weed[v].val[1][1] = 0;
			for (int w = 0; w < 5; w++)
				if (w^1)
					weed[v].val[w][0] = 0;
		}
		else if (s[b] == '1'){
			weed[v].val[2][1] = 0;
			for (int w = 0; w < 5; w++)
				if (w^2)
					weed[v].val[w][0] = 0;
		}
		else if (s[b] == '6'){
			for (int w = 0; w < 3; w++)
				weed[v].val[w][0] = 0;
		}
		else if (s[b] == '7'){
			weed[v].val[3][1] = 0;
			for (int w = 0; w < 5; w++)
				if (w^3)
					weed[v].val[w][0] = 0;
		}
		else
			for (int w = 0; w < 5; w++)
				weed[v].val[w][0] = 0;
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = sprout(weed[v<<1], weed[v<<1^1]);
}

Node smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return ZZ;

	int mid = b + e >> 1;
	return sprout(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q >> s;
	for (int i = 0; i < 5; i++)
		ZZ.val[i][0] = 0;
	plant(1, 0, n);
	while (q--){
		int l, r;	cin >> l >> r, l--;
		int ans = smoke(1, 0, n, l, r).val[0][4];
		if (ans >= INF)
			ans = -1;
		cout << ans << "\n";
	}
	return 0;
}