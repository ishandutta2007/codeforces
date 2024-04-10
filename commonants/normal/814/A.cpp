#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
int a[233];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	if(k>1){puts("Yes");return 0;}
	int lst=-100000;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(!k){
		for(int i=1;i<=n;i++)if(a[i]<=lst){puts("Yes");return 0;}else lst=a[i];
	}else{
		int x;scanf("%d",&x);
		for(int i=1;i<=n;i++)if(!a[i])a[i]=x;
		for(int i=1;i<=n;i++)if(a[i]<=lst){puts("Yes");return 0;}else lst=a[i];
	}
	puts("No");
	return 0;
}