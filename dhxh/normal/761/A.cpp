#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int a, b;
	
	cin >> a >> b;
	
	if(a == 0 and b == 0){
		cout << "NO" << endl;
	}else if(abs(a - b) <= 1){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}