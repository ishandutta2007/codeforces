#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,zero = 0, one = 0;
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++)
		if(s[i] == '0') zero++;
		else one++;
	if(zero == 1 && one == 0 ) {
		cout << 0 << endl;
		return 0;
	}
	cout << '1';
	for(int i=0;i<zero;i++) cout << '0';
	cout << endl;
}