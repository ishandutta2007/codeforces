#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if(a % b){
		return gcd(b, a % b);
	}else{
		return b;
	}
}

int main(){
	int i, j;
	int x, y;
	int a, b, c, d;
	int g;
	int dt;
	int t;
	
	cin >> a >> b;
	cin >> c >> d;
	
	dt = abs(b - d);
	
	g = gcd(a, c);
	
	if(dt % g){
		cout << -1 << endl;
	}else{
		while(b != d){
			if(b < d){
				b += a;
			}else{
				d += c;
			}
		}
		
		cout << b << endl;
	}
	
	return 0;
}