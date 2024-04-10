#include <iostream>

using namespace std;

int main()
{
	int n, k, a[200000], ans = 0, s = 0, ms = 0;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		if(x) {
			ans += a[i];
			a[i] = 0;
		}
	}
	for(int i=0;i<k;i++) s += a[i];
	ms = s;
	for(int i=1;i<n-k+1;i++) {
		ms = max(ms, s-a[i-1]+a[k+i-1]);
		s += -a[i-1]+a[k+i-1];
	}
	cout << ans + ms << endl;;
}