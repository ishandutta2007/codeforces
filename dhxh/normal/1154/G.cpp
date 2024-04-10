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

int cnt[maxn * 10];

int a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long gcd(long long x, long long y){
	if(!y){
		return x;
	}else{
		return gcd(y, x % y);
	}
}

int main(){
	int i, j;
	long long x, y;
	int ansa = 0, ansb = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		x = read();
		cnt[x]++;
		a[i] = x;
	}
	
	x = 1e18, y = 1e18;
	
	for(i=1;i<=1e7;i++){
		vector <long long> vec;
		for(j=i;j<=1e7;j+=i){
			if(cnt[j] > 1){
				vec.push_back(j);
				vec.push_back(j);
				break;
			}
			if(cnt[j]){	
				vec.push_back(j);
				if(vec.size() >= 2){
					break;
				}
			}
		}
		
		if(vec.size() >= 2){
			if(vec[0] / gcd(vec[0], vec[1]) * vec[1] < x / gcd(x, y) * y){
				x = vec[0];
				y = vec[1];
			}
		}
	}
	
	for(i=1;i<=n;i++){
		if(x == a[i]){
			if(a[ansa] != x){
				ansa = i;
				continue;
			}
		}
		if(y == a[i]){
			ansb = i;
		}
	}
	
	printf("%d %d\n", min(ansa, ansb), max(ansa, ansb));
	
	return 0;
}