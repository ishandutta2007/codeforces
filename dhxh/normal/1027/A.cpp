#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

string a;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	bool flag;
	
	cin >> t;
	
	while(t--){
		flag = true;
		cin >> n;
		cin >> a;
		
		for(i=0;i<n;i++){
			if(a[i] != a[n - 1 - i] and abs(a[i] - a[n - 1 - i]) != 2){
				flag = false;
				break;
			}
		}
		
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		
	}
	
	return 0;
}