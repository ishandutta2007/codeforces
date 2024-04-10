#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int l, r;
		cin >> l >> r;
		if(l * 2 <= r)
			cout << l << " " << 2 * l << endl;
		else
			cout << -1 << " " << -1 << endl;
	}
}