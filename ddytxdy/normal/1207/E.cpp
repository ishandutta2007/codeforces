#include<bits/stdc++.h>
using namespace std;
const int N=200,M=(1<<7)-1,P=M<<7;
int a[N],b,c,ans;
int main(){
	for(int i=1;i<=100;i++)a[i]=i;
	printf("? ");
	for(int i=1;i<=100;i++)printf("%d ",a[i]);puts("");
	cout.flush();
	scanf("%d",&b);ans|=b&P;
	for(int i=1;i<=100;i++)a[i]<<=7;
	printf("? ");
	for(int i=1;i<=100;i++)printf("%d ",a[i]);puts("");
	cout.flush();
	scanf("%d",&c);ans|=c&M;
	printf("! %d\n",ans);
	return 0;
}