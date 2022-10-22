#include<bits/stdc++.h>
using namespace std;
#define N 1000000
char a[N+10],b[N+10];
int main(){
	int n,m,x=0,y=0,ans=0,i;scanf("%s%s",a+1,b+1);n=strlen(a+1);m=strlen(b+1);
	for(i=1;i<=m;i++)y+=b[i]=='1';
	for(i=1;i<m;i++)x+=a[i]=='1';
	for(i=m;i<=n;i++)x-=a[i-m]=='1',x+=a[i]=='1',ans+=(x&1)==(y&1);
	printf("%d",ans);
	return 0;
}
/*1
01100010
00110
*/
/*2
1010111110
0110
*/