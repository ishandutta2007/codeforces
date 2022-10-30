#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
int a[maxn];
int rk[maxn];
int n,x1,x2;
int l,r;
bool cmp(int x,int y){
    return a[x]<a[y];
}
bool check(int x,int y){
    int i=n-1;
    while (i>=0&&1LL*(n-i)*a[rk[i]]<y)i--;
    if (i==-1)return false;
    int j =i-1;
    while (j>=0&&1LL*(i-j)*a[rk[j]]<x)j--;
    if (j==-1)return false;
    l=j;r=i;
    return true;
}
int main(){
    scanf("%d%d%d",&n,&x1,&x2);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
        rk[i]=i;
    }
    sort(rk,rk+n,cmp);
   // printf("%d%d\n",rk[0],rk[1]);
    if (check(x1,x2)){
	printf("Yes\n");
	printf("%d %d\n",r-l,n-r);
	for (int i=l;i<r;i++){
		printf("%d ",rk[i]+1);
	}
	printf("\n");
	for (int i=r;i<n;i++){
		printf("%d ",rk[i]+1);
	}
	printf("\n");
    }else if (check(x2,x1)){
        printf("Yes\n");
	printf("%d %d\n",n-r,r-l);
	for (int i=r;i<n;i++){
		printf("%d ",rk[i]+1);
	}
	printf("\n");
	for (int i=l;i<r;i++){
		printf("%d ",rk[i]+1);
	}
	printf("\n");

    }else{
        printf("No\n");
    }
    return 0;
}