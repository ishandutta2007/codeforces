#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if(m >= n * (n - 1) / 2) printf("no solution\n");
	else for(int i = 1;i <= n;i ++) printf("%d %d\n", 0, i);
	return 0;
}