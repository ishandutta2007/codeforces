#include <iostream>

using namespace std;

int main()
{
	int n, m, a[10000] = {0};
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	int ans = 5487;
	for(int i=1;i<=n;i++) 
		ans = min(ans, a[i]);
	cout << ans << endl;
}