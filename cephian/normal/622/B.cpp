#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int h,m,a;
	scanf("%d : %d", &h,&m);
	scanf("%d", &a);
	int t = h*60+m+a;
	printf("%.2d:%.2d\n",(t/60)%24, t%60);
	return 0;
}