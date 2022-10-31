#include <cstdio>
int main(){
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	int res = -1;
	for(int i = 0; i < 10; ++i)
		if((a*10+i)%b==0){
			res = i;
			break;
		}
	if(res >= 0){
		printf("%d%d", a, res); --n;
		while(n--) putchar('0');
	}
	else printf("-1");
	putchar('\n');
	return 0;
}