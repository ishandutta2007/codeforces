#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, l, r, a[MAXN], b[MAXN], p[MAXN], sec[MAXN];

bool cmp(int u, int v){return p[u] > p[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)	cin >> p[i], p[i]--;
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);

	int lst = (int)1e9 + 10;
	for (int i = 0; i < n; i++){
		int v = sec[i];
		b[v] = min(a[v] + lst - 1, r);
		if (b[v] < l){
			cout << "-1\n";
			return 0;
		}
		lst = b[v] - a[v];
	}
	
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << "\n";
	return 0;
}