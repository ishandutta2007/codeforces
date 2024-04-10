#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int a, b, k, h;
int ans;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int ta, tb;
	int fa, fb;
	
	n = read();
	h = read();
	a = read();
	b = read();
	k = read();
	
	while(k--){
		ta = read();
		fa = read();
		tb = read();
		fb = read();
		
		if(ta == tb){
			ans = abs(fa - fb);
		}else{
			if(a <= fa and fa <= b){
				ans = abs(ta - tb) + abs(fa - fb);
			}else{
				if(fa < a){
					ans = (a - fa) + abs(ta - tb) + abs(a - fb);
				}else{
					ans = (fa - b) + abs(ta - tb) + abs(b - fb);
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}