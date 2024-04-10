#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

char a[maxn];

int n;

int main(){
	int i, j;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		if(i < 2){
			a[i] = 'a';
		}else{
			if(a[i - 2] == 'a'){
				a[i] = 'b';
			}else{
				a[i] = 'a';
			}
		}
	}
	
	printf("%s\n", a);
	
	return 0;
}