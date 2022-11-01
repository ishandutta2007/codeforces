#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long n, m, t;

vector <long long> vec;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	long long i, j;
	
	n = read();
	
	vec.push_back((n + 1) * n / 2);
	vec.push_back(1);
	
	for(i=2;i<=sqrt(n)+1;i++){
		if(n % i == 0){
			vec.push_back((1 + n - i + 1) * (n / i) / 2);
			if(n / i <= n / 2){
				j = n / i;
				vec.push_back((1 + n - j + 1) * (n / j) / 2);
			}
		}
	}
	
	sort(vec.begin(), vec.end());
	
	printf("%lld ", vec[0]);
	
	for(i=1;i<vec.size();i++){
		if(vec[i] != vec[i - 1]){
			printf("%lld ", vec[i]);
		}
	}
	printf("\n");
	
	return 0;
}