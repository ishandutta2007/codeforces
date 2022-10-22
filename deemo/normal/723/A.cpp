#include<bits/stdc++.h>

using namespace std;

int a[4];

int main(){
	for (int i = 0; i < 3; i++)	cin >> a[i];
	sort(a, a + 3);
	cout << abs(a[1] - a[0]) + abs(a[2] - a[1]) << endl;
	return 0;
}