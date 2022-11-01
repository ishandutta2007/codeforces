#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

string str;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int l, r;
	int d;
	string ans;
	
	cin >> str;
	
	l = 0;
	r = str.length() - 1;
	
	if(str.length() & 1){
		d = 0;
	}else{
		d = 1;
	}
	
	while(l <= r){
		if(d){
			ans = str[r] + ans;
			r--;
		}else{
			ans = str[l] + ans;
			l++;
		}
		d = !d;
	}
	
	cout << ans << endl;
	
	return 0;
}