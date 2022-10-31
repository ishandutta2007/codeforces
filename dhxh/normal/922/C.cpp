#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	long long i, j;
	
	cin >> n >> m;
	
	for(i=1;i<=min(m, 1000ll);i++){
		if(n % i != i - 1){
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	
	return 0;
}