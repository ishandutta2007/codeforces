#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t;

int a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y, l;
	double minn;
	bool flag;
	
	m = 1e4 + 1;
	
	t = read();
	
	while(t--){
		minn = m * m;
		x = 0;
		y = 0;
		flag = false;
		
		n = read();
		
		for(i=1;i<=n;i++){
			a[i] = read();
		}
		
		sort(a + 1, a + n + 1);
		
		for(i=1;i<n;){
			if(a[i] == a[i + 1]){
				if(flag){
					if(((double)(a[i] + l) * 2) * ((double)(a[i] + l) * 2) / (((double)a[i] * (double)l)) <= minn){
						minn = ((double)(a[i] + l) * 2) * ((double)(a[i] + l) * 2) / (((double)a[i] * (double)l));
						x = l;
						y = a[i];
					}
				}
				l = a[i];
				flag = true;
				i += 2;
			}else{
				i++;
			}
		}
		
		printf("%d %d %d %d\n", x, x, y, y);
		
	}
	
	return 0;
}