#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
int n,suma,sumb;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		suma += a;
	}
	for(int i=1;i<=n;i++){
		int b;
		scanf("%d",&b);
		sumb += b;
	}
	if(suma >= sumb) puts("Yes");
	else puts("No");
	return 0;
}