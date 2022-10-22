#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int t, s, x;	scanf("%d %d %d", &t, &s, &x);
	if (x < t){
		printf("NO\n");
		return 0;
	}
	x -= t;
	if (x == 0){
		printf("YES\n");
		return 0;
	}
	if (x < s){
		printf("NO\n");
		return 0;
	}
	x %= s;
	if (x % s < 2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}