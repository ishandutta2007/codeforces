#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int n, d;
int fen[MAXN];

void add(int v, int val){
	for (v++; v<MAXN; v+=v&-v)
		fen[v] += val;
}

int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	d = min(d, n-d);
	ll ans = 1;
	int cur = 0;
	for (int w = 0; w < n; w++){
		int l = cur, r = cur+d;
		while (r >= n)	r -= n;
		
		int t = 0;
		if (l < r)
			t = get(r) - get(l+1);
		else
			t = get(MAXN - 1) - (get(l + 1) - get(r));
		
		ans += t+1;
		add(l, 1);
		add(r, 1);
		cur = r;
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}