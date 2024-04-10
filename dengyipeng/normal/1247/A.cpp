#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int a,b;

int main(){
	scanf("%d%d",&a,&b);
	if (a==b) printf("%d1 %d2\n",a,b);
	else if (a==b-1) printf("%d9 %d0\n",a,b);
	else if (a==9&&b==1) printf("9 10\n");  
	else printf("-1");
}