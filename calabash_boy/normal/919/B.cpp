#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
typedef long long LL;
using namespace std;
int k;
int cnt = 0;
LL i = 1;
int cal(int x) {
	int temp = 0;
	while(x > 0) {
		temp += (x % 10);
		x /= 10;
	}
	return temp;
}
int main() {
	scanf("%d",&k);
	while(cnt < k) {
		if(cal(i) == 10) {
			cnt++;
		}
		i++;
	}
	cout << i-1 << endl;
	return 0;
}