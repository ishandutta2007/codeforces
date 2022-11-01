#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
int n,a[N],r=-1,lim=1e9;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2,dat;i<=n;i++){
		dat=abs(a[i]-a[i-1]);
		if(dat!=1){
			if(r==-1)r=dat;else if(r!=dat){puts("NO");return 0;}
		}
	}
	if(!r){puts("NO");return 0;}
	if(r==-1){printf("YES\n%d %d\n",lim,lim);return 0;}
	for(int i=2,dat,x,y;i<=n;i++){
		dat=abs(a[i]-a[i-1]);x=min(a[i-1],a[i]);y=max(a[i-1],a[i]);
		if(dat==1&&x%r==0&&y%r==1){puts("NO");return 0;}
	}
	printf("YES\n%d %d\n",lim,r);
	return 0;
}