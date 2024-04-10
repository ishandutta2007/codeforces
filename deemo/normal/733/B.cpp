#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN], b[MAXN], tot, t1, t2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i], tot += a[i] + b[i], t1 += a[i], t2 += b[i];
	
	int ans = -1;
	int mx = abs(t1 - t2);
	for (int i = 0; i < n; i++){
		t1 -= a[i];
		t2 -= b[i];
		t1 += b[i];
		t2 += a[i];

		if (abs(t1 - t2) > mx){
			mx = abs(t1 - t2);
			ans = i;
		}

		t1 += a[i];
		t2 += b[i];
		t1 -= b[i];
		t2 -= a[i];
	}
	cout << ans+1 << "\n";
	return 0;
}