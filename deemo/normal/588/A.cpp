#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	int mini = 1e9, ans = 0;
	while (n--){
		int a, b;	scanf("%d%d", &a, &b);
		mini = min(mini, b);
		ans += a * mini;
	}
	printf("%d\n", ans);
	return 0;
}