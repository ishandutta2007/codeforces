#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if(n>m) swap(n, m);
	if(n==1) {
		if(m%6==0)printf("%d\n",m);else 
		if(m%6<=3)printf("%d\n",m-(m%6));
		else printf("%d\n",m-(6-m%6));
	} else 
	if(n==2&&m==2)printf("%d\n",0);
	else if(n==2&&m==3)printf("%d\n",4);
	else if(n==2&&m==7)printf("%d\n",12);
	else {
		if(n%2==1&&m%2==1)printf("%I64d\n",1ll*n*m-1);
		else printf("%I64d\n",1ll*n*m);
	}
}