#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,a[N],b[N],ans=0,p;
bool check(){
	for(int i=p,j=1;i<=n;i++,j++){
		if(a[i]!=j)return 0;
	}
	if(p!=1&&a[p-1]!=0)return 0;
	for(int i=1;i<p-1;i++)if(a[i]&&a[i]<=(n-p+1)+i)return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)if(a[i]==1)p=i;
	if(p&&check()){
		printf("%d",p-1);return 0;
	}
	for(int i=1;i<=n;i++)if(a[i]){
		if(i-(a[i]-1)>ans)ans=i-(a[i]-1);
	}
	ans+=n;
	printf("%d",ans);
}
//4
//0 3 0 4
//0 0 1 2