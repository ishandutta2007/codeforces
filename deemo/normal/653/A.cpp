#include<iostream>
#include<algorithm>

using namespace std;

int n, a[100];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	int sz = unique(a, a + n) - a;
	bool found = 0;
	for (int i = 0; i < sz - 2; i++)
		if (a[i + 2] == a[i] + 2)	found = 1;

	if (found)
		cout << "YES\n";
	else
		cout << "NO\n";
	return	0;
}