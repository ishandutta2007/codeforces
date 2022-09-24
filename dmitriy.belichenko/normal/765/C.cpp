#include <iostream>
#include<algorithm>
#include<vector>
#include <set>
#include<string>
#include<vector>
using namespace std;
long long n;
int main()
{
	//freopen("ladder.in", "r", stdin);
	//freopen("ladder.out", "w", stdout);
	string s;
	int a, b , k;
	cin >> k >> a >> b;
	int ans = a / k + b / k;
	int ost1 = a % k;
	int ost2 = b % k;
	if (ost1 != 0 && b / k == 0)
	{
		cout << -1;
		return 0;
    }
	if (ost2 != 0 && a / k == 0)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
}