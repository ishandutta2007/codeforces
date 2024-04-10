#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	long long x, y, a;
	long long ans;
	
	cin >> x >> y >> a;
	
	ans = (x / a) * (y / a);
	
	if(x % a){
		ans = ans + y / a;
	}
	
	if(y % a){
		ans = ans + x / a;
	}
	
	if(x % a and y % a){
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}