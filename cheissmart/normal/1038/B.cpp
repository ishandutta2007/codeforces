#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n < 3) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		cout << 2 << " " << 1 << " " << n << endl;
		cout << n - 2 << " ";
		for(int i=2;i<n;i++)
			cout << i << " ";
		cout << endl;
		
	}
}