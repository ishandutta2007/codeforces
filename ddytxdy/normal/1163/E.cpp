#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=4e5+50;
int n,a[N],d[20],b[20],num,ans[N];
void ins(int x){
	int y=x;
	for(int i=18;~i;i--){
		if((x>>i)&1){
			if(d[i])x^=d[i];
			else{
				d[i]=x,b[i]=y,num++;break;
			}
		}
	}
}
void solve(int l,int r,int x){
	if(x<0)return;
	int mid=(l+r)>>1;
	ans[mid]=b[x];
	solve(l,mid-1,x-1);solve(mid+1,r,x-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=18;~i;i--){
		for(int j=0;j<=18;j++)d[j]=0;
		num=0;
		for(int j=1;j<=n;j++){
			if(a[j]>=1<<i)break;
			ins(a[j]);
		}
		if(num==i){
			solve(1,(1<<i)-1,i-1);
			int x=0;
			printf("%d\n",i);
			for(int j=0;j<1<<i;j++)printf("%d ",x^=ans[j]);
			return 0;
		}
	}
	return 0;
}