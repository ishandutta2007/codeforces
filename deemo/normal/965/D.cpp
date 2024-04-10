#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int w, l, a[MAXN], pt[MAXN];

bool ok(int mid){
	int r = 0, i;
	for (i = 0; i + l < w && pt[w-1] - pt[i] >= mid; i++){
		while (pt[r] - pt[i] < mid) r++;
		if (r - i > l) return false;
	}
	if (i+l < w) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> w >> l;
	for (int i = 1; i < w; i++) cin >> a[i], pt[i] = pt[i-1] + a[i];

	int lo = 0, hi = (int)1e9 + 1;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (ok(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << "\n";
	return 0;
}