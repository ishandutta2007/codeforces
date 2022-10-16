#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int c = n % 3;
	if(c != 2) 
		cout << 1 << " " << 1 << " " << n-2 << endl;
	else {
		cout << 2 << " " << 2 << " " << n-4 << endl;
	}
}