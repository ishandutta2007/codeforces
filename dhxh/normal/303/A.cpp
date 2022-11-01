#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int a[maxn];
int b[maxn];
int c[maxn];

int n;

int main(){
	int i, j;
	
	cin >> n;
	
	if(n % 2 == 0){
		cout << -1 << endl;
		return 0;
	}
	
	for(i=0;i<n;i++){
		a[i] = i;
		b[i] = i;
		c[i] = (2 * i) % n;
	}
	
	for(i=0;i<n;i++){
		cout << a[i] << " ";
	}
	
	cout << endl;
	
	for(i=0;i<n;i++){
		cout << b[i] << " ";
	}
	
	cout << endl;
	
	for(i=0;i<n;i++){
		cout << c[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}