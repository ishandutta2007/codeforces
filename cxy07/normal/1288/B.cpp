//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

int T;
int a,b,cnt;
bool flag;

signed main () {
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld%lld",&a,&b);
		cnt = 0; flag = true;
		int tmp = b;
		while(tmp) {
			flag &= (tmp % 10 == 9);
			cnt++,tmp /= 10;
		}
		printf("%lld\n",(cnt - (!flag)) * a);
	}
	return 0;
}