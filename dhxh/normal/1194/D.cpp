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
	
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		
		if(n < m){
			if(n % 3 == 0){
				cout << "Bob" << endl;
			}else{
				cout << "Alice" << endl;
			}
			continue;
		}
		
		bool flag = (m % 3 == 0);
		
		if(flag){
			n %= (m + 1);
			if(n == m){
				cout << "Alice" << endl;
			}else{
				if(n % 3 == 0){
					cout << "Bob" << endl;
				}else{
					cout << "Alice" << endl;
				}
			}
		}else{
			if(n % 3 == 0){
				cout << "Bob" << endl;
			}else{
				cout << "Alice" << endl;
			}
		}
	}
	
	return 0;
}