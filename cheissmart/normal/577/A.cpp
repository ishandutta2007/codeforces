#include <iostream>

using namespace std;

int main()
{
	int n, x, ans = 0;
	cin >> n >> x;
	for(int i=1;i<=x && i<=n;i++)
		if(x%i == 0 && i <= n && x/i <= n)
			ans++;
	cout << ans << endl;
}