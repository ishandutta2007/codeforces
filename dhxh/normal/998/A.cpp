#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n, m;

int a[105];

int main(){
	int i, j;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
		m += a[i];
	}
	
	if(n == 1){
		cout << -1 << endl;
	}else if(n == 2 and a[1] == a[2]){
		cout << -1 << endl;
	}else{
		if(a[1] * 2 == m){
			cout << 2 << endl;
			cout << "1 2" << endl;
		}else{
			cout << 1 << endl;
			cout << 1 << endl;
		}
	}
	
	return 0;
}