#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int n,ret,ans[10],now,x;bool vis[N];
int main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("? %d %d %d %d\n",i,1,i,n);
		cout.flush();
		scanf("%d",&ret);
		if(ret&1)ans[++now]=i;
		if(now==2)break;
	}
	if(ans[1]){
		int l=1,r=n,anss;
		while(l<=r){
			int mid=(l+r)>>1;
			printf("? %d %d %d %d\n",ans[1],l,ans[1],mid);
			cout.flush();
			scanf("%d",&ret);
			if(ret&1)r=mid-1,anss=mid;
			else l=mid+1;
		}
		ans[3]=anss;
		l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			printf("? %d %d %d %d\n",ans[2],l,ans[2],mid);
			cout.flush();
			scanf("%d",&ret);
			if(ret&1)r=mid-1,anss=mid;
			else l=mid+1;
		}
		ans[4]=anss;
		printf("! %d %d %d %d\n",ans[1],ans[3],ans[2],ans[4]);
		return 0;
	}
	now=2;
	for(int i=1;i<=n;i++){
		x=rand()%n+1;
		if(vis[x]){
			i--;continue;
		}
		printf("? %d %d %d %d\n",1,x,n,x);
		vis[x]=1;
		cout.flush();
		scanf("%d",&ret);
		if(ret&1)ans[++now]=x;
		if(now==4)break;
	}
	int l=1,r=n,anss;
	while(l<=r){
		int mid=(l+r)>>1;
		printf("? %d %d %d %d\n",l,ans[3],mid,ans[3]);
		cout.flush();
		scanf("%d",&ret);
		if(ret&1)r=mid-1,anss=mid;
		else l=mid+1;
	}
	ans[1]=anss;
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		printf("? %d %d %d %d\n",l,ans[4],mid,ans[4]);
		cout.flush();
		scanf("%d",&ret);
		if(ret&1)r=mid-1,anss=mid;
		else l=mid+1;
	}
	ans[2]=anss;
	printf("! %d %d %d %d\n",ans[1],ans[3],ans[2],ans[4]);
	return 0;
}