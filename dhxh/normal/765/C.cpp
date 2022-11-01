#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int k, a, b;

int main(){
	int i, j;
	int ans = 0;
	int x, y;
	
	cin >> k >> a >> b;
	
	x = a / k;
	y = b / k;
	
	if(x == 0 and y == 0){
		cout << -1 << endl;
	}else if(x == 0 and y != 0 and b % k){
		cout << -1 << endl;
	}else if(x != 0 and y == 0 and a % k){
		cout << -1 << endl;
	}else{
		cout << x + y << endl;
	}
	
	return 0;
}