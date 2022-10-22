#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int g[]={n%4,(n+1)%4,(n+2)%4};
	const int ord[]={4,1,3,2};
	int mn=10,mnid;
	for(int i=0;i<=2;i++)if(ord[g[i]]<mn)mn=ord[g[i]],mnid=i;
	printf("%d %c",mnid,'A'+mn-1);
	return 0;
}
/*1
33
*/
/*2
98
*/