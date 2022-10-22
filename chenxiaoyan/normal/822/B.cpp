#include<bits/stdc++.h>
using namespace std;
#define N 1000
#define M N
#define inf 0x3f3f3f3f
int n,m;
char a[N+1],b[M+1];
int main(){
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	int mn=inf,mnid;
	for(int i=1;i+n-1<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++)cnt+=a[j]!=b[j+i-1];
		if(cnt<mn)mn=cnt,mnid=i;
	}
	printf("%d\n",mn);
	for(int i=1;i<=n;i++)if(a[i]!=b[i+mnid-1])printf("%d ",i);
	return 0;
}
/*1
3 5
abc
xaybz
*/
/*2
4 10
abcd
ebceabazcd
*/