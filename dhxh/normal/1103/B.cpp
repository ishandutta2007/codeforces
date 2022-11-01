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

bool query(int x, int y){
	char ch;
	cout << "? " << x << " " << y << endl;
	cin >> ch;
	if(ch == 'x'){
		return true;
	}else{
		return false;
	}
}

int main(){
	int i, j;
	int x, y, t;
	int l, r;
	
	while(cin >> str){
		if(str != "start"){
			break;
		}
		
		x = 0;
		y = 1;
		
		if(query(x, y)){
			cout << "! " << x + 1 << endl;
			continue;
		}
		
		x = 0;
		y = 0;
		
		t = 1;
		
		while(t){
			if(query(x + t, y + 2 * t)){
				t /= 2;
				break;
			}else{
				t *= 2;
			}
		}
		
		x = t;
		
		t /= 2;
		
		while(t){
			if(!query(x + t, 2 * x + 2 * t)){
				x += t;
			}
			t /= 2;
		}
		
		if(query(2 * x, 2 * x + 1)){
			cout << "! "  << 2 * x + 1 << endl;
		}else{
			cout << "! " << 2 * x + 2 << endl;
		}
	}
	
	return 0;
}