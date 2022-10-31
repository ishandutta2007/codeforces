#include<stdio.h>
#include<algorithm>
using namespace std;
#define R register int
int a[100000];
inline int Min(int a,int b){
	return a<b?a:b;
}
inline int DFS(int l,int r,int x,int ans,int base){
	if(l>=r){
		return 2e9;
	}
	int mid=lower_bound(a+l,a+r,base|(1<<x))-a;
	if(l!=mid&&r!=mid){
		ans|=1<<x;
	}
	if(x==0){
		return ans;
	}
	return Min(DFS(l,mid,x-1,ans,base),DFS(mid,r,x-1,ans,base|(1<<x)));
}
int main(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	printf("%d",DFS(0,n,29,0,0));
	return 0;
}