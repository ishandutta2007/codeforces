#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

long long n, m;

long long ans = 0;

int main(){
	long long i, j, k;
	
	cin >> n;
	
	for(i=0;i<=min(8ll,n);i++){
		for(j=0;j<=min(8ll,n-i);j++){
			if(i >= 1 and j >= 5){
				continue;
			}else{
				ans += n - i - j + 1;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}