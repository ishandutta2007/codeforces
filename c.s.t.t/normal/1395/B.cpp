#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d %d\n",c,d);
	for(int i=1;i<=a;i++)if(i!=c)printf("%d %d\n",i,d);
	for(int i=1;i<=b;i++){
		if(i==d)continue;
		bool dir=(i&1);
		if(i>d)dir^=1;
		if(dir==1)for(int j=a;j;j--)printf("%d %d\n",j,i);
		else for(int j=1;j<=a;j++)printf("%d %d\n",j,i);
	}
	return 0;
}