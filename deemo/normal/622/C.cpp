#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m, a[MAXN], nxt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> a[i];
	nxt[n - 1] = n;
	for (int i = n - 2; i >= 0; i--)
		if (a[i] == a[i + 1])	
			nxt[i] = nxt[i + 1];
		else
			nxt[i] = i + 1;

	while (m--){
		int l, r, x;	cin >> l >> r >> x;	l--;
		if (a[l] != x)
			cout << l + 1 << "\n";
		else if (nxt[l] < r)
			cout << nxt[l] + 1 << "\n";
		else
			cout << "-1\n";
	}
	return	0;
}