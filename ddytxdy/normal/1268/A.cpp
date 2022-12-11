#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,k;char a[N],fl=0;
int main(){
	scanf("%d%d%s",&n,&k,a+1);
	for(int i=1;i<=n-k;i++)
		if(a[i+k]>a[i]){fl=1;break;}
		else if(a[i+k]<a[i]){fl=2;break;}
	printf("%d\n",n);
	if(!fl)puts(a+1),exit(0);
	if(fl==1){
		int x=k;a[x]++;
		while(a[x]>'9')a[x]='0',x--,a[x]++;
	}
	for(int i=1;i<=n-k;i++)a[i+k]=a[i];
	puts(a+1);
	return 0;
}