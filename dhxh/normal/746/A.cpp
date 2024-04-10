#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int a, b, c;

int main(){
	int i, j;
	int x;
	
	cin >> a >> b >> c;
	
	x = min(a, min(b / 2, c / 4));
	
	cout << 7 * x << endl;
	
	return 0;
}