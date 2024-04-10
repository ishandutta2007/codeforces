#include<bits/stdc++.h>

using namespace std;

int a[4];

int main(){
	for (int i = 0; i < 4; i++)	cin >> a[i];
	int b = a[0]^a[1];
	int c = a[2]|a[3];
	int d = a[1]&a[2];
	int e = a[0]^a[3];
	int f = b&c;
	int g = d|e;
	cout << (f^g) << "\n";
	return 0;
}