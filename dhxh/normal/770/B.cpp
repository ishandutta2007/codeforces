#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m;

string str;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long getn(int x, int y){
	int i, j;
	long long ret = 0;
	for(i=0;i<x;i++){
		ret = ret * 10 + str[i] - '0';
	}
	
	ret--;
	
	for(i=1;i<=y;i++){
		ret = ret * 10 + 9;
	}
	
	return ret;
}

long long getnb(int x, int y){
	int i, j;
	long long ret = 0;
	for(i=0;i<x;i++){
		ret = ret * 10 + str[i] - '0';
	}
	
	for(i=1;i<=y;i++){
		ret = ret * 10 + 0;
	}
	
	return ret;
}

int main(){
	int i, j;
	long long ans = 0;
	int maxn = 0;
	int a = 0;
	
	cin >> str;
	
	for(i=0;i<str.length();i++){
		a += str[i] - '0';
		
		if(a - 1 + 9 * (str.length() - i - 1) >= maxn){
			maxn = a - 1 + 9 * (str.length() - i - 1);
			ans = getn(i + 1, str.length() - i - 1);
		}
		
		if(a >= maxn){
			maxn = a;
			ans = max(ans, getnb(i + 1, str.length() - i - 1));
		}
		
	}
	
	cout << ans << endl;
	
	return 0;
}