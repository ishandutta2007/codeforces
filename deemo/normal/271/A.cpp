#include<iostream>

using namespace std;

int c[30];

bool ok(int x){
	for (int i = 0; i < 20; i++)	c[i] = 0;
	while (x){
		int t = x % 10;
		c[t]++;
		if (c[t] > 1)	return	false;
		x /= 10;
	}
	return	true;
}

int main(){
	int n;
	cin >> n;
	n++;
	while (!ok(n))	n++;
	cout << n << endl;
	return 0;
}