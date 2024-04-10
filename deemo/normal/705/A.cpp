#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	for (int i = 1; i < n; i++)
		if (i&1)
			cout << "I hate that ";
		else
			cout << "I love that ";
	if (n & 1)
		cout << "I hate it\n";
	else
		cout << "I love it\n";
	return 0;
}