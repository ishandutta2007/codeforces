#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int n, a, t;	cin >> n >> a >> t;	a--;
	a += t;
	while (a < 0)	a += n;
	cout << (a%n) + 1 << "\n";
	return	0;
}