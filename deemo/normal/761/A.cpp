#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b;	cin >> a >> b;
	if (a +b == 0)
		cout << "NO\n";
	else if (abs(a-b) <= 1)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}