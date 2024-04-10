#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e4 + 4;

int n, q;
vector<int> vec[MAXN<<2];
bitset<MAXN> ans, can, sv[MAXN<<2];

void add(int v, int b, int e, int l, int r, int x){
	if (l <= b && e <= r){
		vec[v].push_back(x);
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	add(v<<1, b, mid, l, r, x);
	add(v<<1^1, mid, e, l, r, x);
}

void go(int v, int b, int e){
	sv[v] = can;
	for (int x:vec[v])
		can |= can<<x;
	ans |= can;
	if (e - b > 1){
		int mid = b + e >> 1;
		go(v<<1, b, mid);
		go(v<<1^1, mid, e);
	}
	can = sv[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < q; i++){
		int l, r, x; cin >> l >> r >> x, l--;
		add(1, 0, n, l, r, x);
	}
	can[0] = ans[0] = 1;
	go(1, 0, n);

	int c = 0;
	for (int i = 1; i <= n; i++)
		if (ans[i])
			c++;
	cout << c << "\n";
	for (int i = 1; i <= n; i++)
		if (ans[i])
			cout << i << " ";
	cout << "\n";
	return 0;
}