#include <iostream>

using namespace std;

int a[200005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 1, ct = 1;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=1;i<n;i++) {
		if(a[i] > 2*a[i-1]){
			ct = 1;
		} else {
			ct++;
			ans = max(ans, ct);
		}
	}
	cout << ans << endl;
}