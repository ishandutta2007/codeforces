#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k;	cin >> n >> m >> k;
	cout << (k-1)/(2*m)+1 << " ";
	cout << (k-1)%(2*m)/2+1 << " ";
	
	if (k&1)
		cout << "L\n";
	else
		cout << "R\n";
	return 0;
}