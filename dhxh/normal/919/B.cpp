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
	int cnt = 0;
	
	cin >> n;
	
	for(i=1;i<=1e8;i++){
		int t = i;
		int c = 0;
		while(t){
			c += t % 10;
			t /= 10;
		}
		if(c == 10){
			cnt++;
			if(cnt == n){
				cout << i << endl;
				return 0;
			}
		}
	}
	
	return 0;
}