#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int ZZ = 300;

int n, a[MAXN], d[ZZ][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int j = 1; j < ZZ; j++){
		for (int i = n-1; ~i; i--){
			d[j][i] = 1;
			if (i+j+a[i] < n)
				d[j][i] += d[j][i+j+a[i]];
		}
	}

	int q;	cin >> q;
	while (q--){
		int p, k; cin >> p >> k, p--;
		if (k < ZZ)
			cout << d[k][p] << "\n";
		else{
			int ans = 0;
			while (p < n){
				ans++;
				p += a[p]+k;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}