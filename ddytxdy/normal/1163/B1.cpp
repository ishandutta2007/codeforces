#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50,M=1e5;
int n,a[N],s[N],x,y,num1,num2,ss[N];bool flag;
struct node{
	int l,r,sum;
}t[N*4];
//void build(int x,int l,int r){
//	t[x].l=l;t[x].r=r;
//	if(l==r){
//		t[x].sum=ss[l];return;
//	}
//	int mid=(l+r)>>1;
//	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
//	t[x].sum=t[x<<1].sum+t[x<<1|1].sum;
//}
//void change(int x,int p){
//	if(t[x].l==t[x].r){
//		t[x].sum=ss[p];return;
//	}
//	int mid=(t[x].l+t[x].r)>>1;
//	if(p<=mid)change(x<<1,p);
//	else change(x<<1|1,p);
//	t[x].sum=t[x<<1].sum+t[x<<1|1].sum;
//}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[a[i]]++;
	for(int i=1;i<=M;i++)ss[s[i]]++;
//	build(1,1,M);
	for(int i=n;i;i--){
		x=y=num1=num2=0;flag=1;
		for(int j=1;j<=10;j++){
			if(!s[j])continue;
			if(!x)x=s[j];
			else if(!y&&s[j]!=x)y=s[j];
			if(s[j]==x)num1++;
			else if(s[j]==y)num2++;
			else flag=0;
		}
		s[a[i]]--;
		if(!flag)continue;
		if(!y&&(num1==1||x==1)||num1==1&&(x==1||x==y+1)||num2==1&&(y==1||y==x+1)){
			printf("%d",i);return 0;
		}
	}
	printf("0");
	return 0;
}