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
void build(int x,int l,int r){
	t[x].l=l;t[x].r=r;
	if(l==r){
		t[x].sum=ss[l];return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	t[x].sum=t[x<<1].sum+t[x<<1|1].sum;
}
void change(int x,int p){
	if(t[x].l==t[x].r){
		t[x].sum=ss[p];return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(p<=mid)change(x<<1,p);
	else change(x<<1|1,p);
	t[x].sum=t[x<<1].sum+t[x<<1|1].sum;
}
int askl(int x){
	if(t[x].l==t[x].r)return t[x].l;
	if(t[x<<1].sum)return askl(x<<1);
	return askl(x<<1|1);
}
int askr(int x){
	if(t[x].l==t[x].r)return t[x].l;
	if(t[x<<1|1].sum)return askr(x<<1|1);
	return askr(x<<1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[a[i]]++;
	for(int i=1;i<=M;i++)ss[s[i]]++;
	build(1,1,M);
	for(int i=n;i;i--){
		int l=askl(1),r=askr(1);
		int x=ss[l],y=ss[r],sum=t[1].sum;
//		printf("%d %d %d %d %d %d\n",i,l,r,x,y,sum);
		ss[s[a[i]]]--;change(1,s[a[i]]);
		s[a[i]]--;ss[s[a[i]]]++;
		if(s[a[i]])change(1,s[a[i]]);
		if(l==r&&(x==1||l==1)){
			printf("%d",i);return 0;
		}
		if(x+y!=sum)continue;
		if(y==1&&r==l+1||l==1&&x==1){
			printf("%d",i);return 0;
		}
	}
	printf("0");
	return 0;
}
//15
//1 2 2 3 3 3 4 4 4 4 5 5 5 5 5