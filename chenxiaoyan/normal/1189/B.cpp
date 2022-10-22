#include<bits/stdc++.h>
using namespace std;
#define N 100000
int a[N+1];
int main(){
	int n,i;scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(a[n]>=a[n-1]+a[n-2])return printf("NO"),0;
	puts("YES");
	swap(a[n-1],a[n]);
	for(i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
/*1
3
2 4 3
*/
/*2
5
1 2 3 4 4
*/
/*3
3
13 8 5
*/
/*4
4
1 10 100 1000
*/