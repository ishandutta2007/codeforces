#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

string a[55], b[55];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n >> m;
	
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	
	for(i=0;i<m;i++){
		cin >> b[i];
	}
	
	cin >> t;
	
	while(t--){
		int x;
		cin >> x;
		x--;
		cout << a[x % n] << b[x % m] << endl;
	}
	
	return 0;
}