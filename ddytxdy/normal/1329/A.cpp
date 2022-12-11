#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,a[N],l[N],r[N];
int main(){
	scanf("%d%d",&n,&m);l[m+1]=n+1;r[m+1]=n+1;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=m;i;i--){
		l[i]=max(1,l[i+1]-a[i]);r[i]=min(r[i+1]-1,n-a[i]+1);
	}
	if(l[1]>1||r[1]<1)puts("-1"),exit(0);l[1]=r[1]=1;
	for(int i=1;i<=m;i++){
		printf("%d ",l[i]);
		l[i+1]=max(l[i+1],l[i]+1);//r[i+1]=min(r[i+1],l[i]+1);
	}
	// for(int i=m;i;i--)if()
	// for(int i=m;i;i--){
		
	// }
}