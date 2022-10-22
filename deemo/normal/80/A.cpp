#include<iostream>

using namespace std;

bool pr(int n){
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)	return	false;
	return	true;
}

int main(){
	int n;	cin >> n;
	n++;
	while (!pr(n))	n++;
	int m;	cin >> m;
	if (m == n)
		cout << "YES\n";
	else
		cout << "NO\n";
	return	0;
}