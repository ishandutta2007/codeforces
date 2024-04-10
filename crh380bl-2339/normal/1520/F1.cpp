#include<bits/stdc++.h>
using namespace std;
void ASK(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
}
int main(){
	int n,t,m,x,ans;
	scanf("%d%d%d",&n,&t,&m);
	int L=1,R=n,mid;
	while(L<=R){
		mid=(L+R)>>1;
		ASK(1,mid);
		scanf("%d",&x);
		if(mid-x>=m){
			ans=mid;
			R=mid-1;
		}
		else L=mid+1;
	}
	printf("! %d\n",ans);
	return 0;
}