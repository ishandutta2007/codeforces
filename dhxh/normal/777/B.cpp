#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n;

int a[15] = {0};
int b[15] = {0};
int c[15] = {0};
int d[15] = {0};

int main(){
	int i, j;
	int ans = 0;
	char ch;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> ch;
		a[ch - '0']++;
		c[ch - '0']++;
	}
	
	for(i=1;i<=n;i++){
		cin >> ch;
		b[ch - '0']++;
		d[ch - '0']++;
	}
	
	for(i=0;i<=9;i++){
		if(a[i] <= b[i]){
			b[i] = b[i] - a[i];
			a[i] = 0;
		}else{
			a[i] = a[i] - b[i];
			b[i] = 0;
		}
	}
	
	for(i=9;i>=0;i--){
		if(a[i] > 0){
			ans += a[i];
		}else if(b[i] > 0){
			j = i;
			while(b[i] > 0 and j >= 0){
				if(a[j] >= b[i]){
					a[j] -= b[i];
					b[i] = 0;
				}else{
					b[i] -= a[j];
					a[j] = 0;
				}
				j--;
			}
		}
	}
	
	cout << ans << endl;
	
	ans = 0;
	
	for(i=9;i>0;i--){
		j = i - 1;
		while(d[i] > 0 and j >= 0){
			if(c[j] >= d[i]){
				c[j] -= d[i];
				ans += d[i];
				d[i] = 0;
			}else{
				d[i] -= c[j];
				ans += c[j];
				c[j] = 0;
			}
			
			j--;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}