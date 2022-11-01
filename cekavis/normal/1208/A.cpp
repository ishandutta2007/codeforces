#include<bits/stdc++.h>

using namespace std;
#define ll long long

int T, a, b, n;
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &a, &b, &n);
		printf("%d\n", n%3==2?a^b:(n%3==1?b:a));
	}
	return 0;
}