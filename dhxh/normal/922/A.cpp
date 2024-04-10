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
	
	cin >> n >> m;
	
	if(m == 0){
		cout << "No" << endl;
		return 0;
	}
	
	m--;
	
	if(n < m){
		cout << "No" << endl;
		return 0;
	}
	
	n -= m;
	
	if(n & 1){
		cout << "No" << endl;
		return 0;
	}
	
	if(n > 0 and m == 0){
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	
	return 0;
}