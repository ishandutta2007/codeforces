#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	if(n % 2){
		cout << "black" << endl;
	}else{
		cout << "white" << endl;
		cout << "1 2" << endl;
	}
	
	return 0;
}