#include<bits/stdc++.h>
using namespace std;
int bit[300003],n,m,ans[300003];
void add(int x,int y){
	while(x<=n)
	{
		bit[x]+=y;
		x=1+(x|(x-1));
	}
}
int inq(int x){
	int ret=0;
	while(x>0){
		ret+=bit[x];
		x&=(x-1);
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)add(i,1);
	for(int i=1;i<=m;i++){
		int from,to,winn,num,l,r;
		scanf("%d %d %d",&from,&to,&winn);
		num=inq(to)-inq(from-1);
		int last=inq(from-1);
		while(num--){
			l=from;r=to;
			while(l<r){
				int mid=(l+r)/2;
				if(inq(mid)==last)
					l=mid+1;
				else r=mid;
			}
			ans[l]=winn;
			add(l,-1);
		}
		add(winn,1);
		ans[winn]=0;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}