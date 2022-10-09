#include<iostream>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x;
	cin >> x;
	if(x % 2 == 0 && x > 2)
		cout << "YES\n";
	else
		cout << "NO\n";
}