#include<iostream>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int z = n;
	for (int i = 0; i < k; i++, z--)
		cout << z << " ";
	for (int j = 1; j <= z; j++)
		cout << j << " ";
	cout << endl;
	return 0;
}