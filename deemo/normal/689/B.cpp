#include<iostream>

using namespace std;

const int MAXN = 2e5 + 10;

int n, q[MAXN], ans[MAXN], nxt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> nxt[i], nxt[i]--, ans[i] = 1e9;
	int h = 0, t = 0;
	q[t++] = 0;
	ans[0] = 0;
	while (h < t){
		int v = q[h++];
		if (v + 1 < n && ans[v + 1] > ans[v] + 1)
			ans[v + 1] = ans[v] + 1, q[t++] = v + 1;
		if (v && ans[v - 1] > ans[v] + 1)
			ans[v - 1] = ans[v] + 1, q[t++] = v - 1;
		if (ans[nxt[v]] > ans[v] + 1)
			ans[nxt[v]] = ans[v] + 1, q[t++] = nxt[v];
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}