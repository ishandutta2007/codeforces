#include <iostream>

using namespace std;

int a[10000000];

int main()
{
	int n, k, ans = 0;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int i;
	for(i=0;i<n && a[i] <= k;i++)
		ans++;
	for(int j=n-1;j >= i && a[j] <= k;j--)
		ans++;
	cout << ans << endl;
}