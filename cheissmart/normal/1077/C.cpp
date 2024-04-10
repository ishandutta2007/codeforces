#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+87;

long long pmx[N], smx[N], a[N], psm = 0;

long long get(long long*arr, int idx) {
	if(idx < 0) return 0;
	return arr[idx];
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	psm = pmx[0] = a[0];
	for(int i=1;i<n;i++) {
		pmx[i] = max(pmx[i-1], a[i]);
		psm += a[i];
	}
	smx[n-1] = a[n-1];
	for(int i=n-2;i>=0;i--) {
		smx[i] = max(smx[i+1], a[i]);
	}
	vector<int> ans;
	for(int i=0;i<n;i++) {
		int mx = max(get(pmx, i-1), smx[i+1]);
		long long sm = psm - a[i];
		if(sm == mx*2) {
			ans.push_back(i+1);
		}
	}
	cout << ans.size() << endl;
	for(int x:ans)
		cout << x << " ";
	cout << endl;
}