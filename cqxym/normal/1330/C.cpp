#include<stdio.h>
#define R register int
int l[100001],ans[100001],mx[100001];
inline int Min(int a,int b,int c){
	a=a<b?a:b;
	return a<c?a:c;
}
int main(){
	int n,m;
	long long s=0;
	scanf("%d%d",&n,&m);
	for(R i=1;i<=m;i++){
		scanf("%d",l+i);
		int tem=i-1+l[i];
		if(tem>n){
			printf("-1");
			return 0;
		}
		mx[i]=mx[i-1];
		if(tem>mx[i]){
			mx[i]=tem;
		}
		s+=l[i];
		ans[i]=i;
	}
	if(s<n){
		printf("-1");
		return 0;
	}
	int q=m,lt=n;
	while(mx[q]<lt){
		lt-=l[q];
		ans[q]=lt+1;
		q--;
	}
	for(R i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}