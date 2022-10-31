#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = min(min(a, b), c), z = max(max(a, b), c), y = a + b + c - x - z;
	int p = d - (y - x), q = d - (z - y);
	cout << max(p, 0) + max(q, 0);
}