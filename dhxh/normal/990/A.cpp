#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, a, b;

int main(){
	int i,j;
	
	cin >> n >> m >> a >> b;
	
	cout << min(n % m * b, (m - n % m) * a) << endl;
	
	return 0;
}