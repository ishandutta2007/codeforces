#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long x, y, p , q;
int main(){
	int tt;
	scanf("%d", &tt);
	while(tt--){
		cin >> x >> y >> p >> q;
		if(p == q){
			if(x == y)
				puts("0");
			else
				puts("-1");
		}
		else if(p == 0){
			if(x == 0)
				puts("0");
			else
				puts("-1");
		}
		else if(x * q == p * y){
			puts("0");
		}
		else if(x * q < p * y){
			long long ans = (y - x + q - p - 1) / (q - p);
			ans = max(ans, (y + q - 1) / q);
			ans = ans * q - y;
			cout << ans << endl;
		}
		else{
			long long t1 = (p + x - 1) / p;
			long long t2 = (y + q - 1) / q;
			long long t = max(t1,t2);
			cout << t * q - y << endl;
		}
	}
	return 0;
}