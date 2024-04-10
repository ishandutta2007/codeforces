#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,pos,cha;bool vis[N];
struct node{
	int x,id;
	bool friend operator <(node a,node b){
		return a.x<b.x;
	}
}a[N];
void find(int x){printf("%d\n",x);exit(0);}
void solve1(){
	bool flag=0;
	for(int i=4;i<=n;i++)if(a[i].x-a[i-1].x!=a[i-1].x-a[i-2].x)flag=1;
	if(!flag)find(a[1].id);
	for(int i=2;i<=n;i++){
		vis[i]=1;flag=0;
		cha=i==2?a[3].x-a[1].x:a[2].x-a[1].x;
		for(int j=2,la=1;j<=n;j++){
			if(vis[j])continue;
			if(a[j].x-a[la].x!=cha)flag=1;
			la=j;
		}
		if(!flag)find(a[i].id);
		vis[i]=0;
	}
	find(-1);
}
int main(){
	scanf("%d",&n);
	if(n==2||n==3){
		puts("1");return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1);
	if(n==4||n==5)solve1();
	if(a[n].x-a[n-1].x==a[2].x-a[1].x)cha=a[n].x-a[n-1].x;
	else cha=a[n-2].x-a[n-3].x;
	for(int i=2;i<=n;i++){
		if(a[i].x-a[i-1].x!=cha){
			if(!pos)pos=i;
			else if(pos!=i-1)find(-1);
		}
	}
	if(!pos)find(a[1].id);
	if(pos==n||a[pos+1].x-a[pos-1].x==cha)find(a[pos].id);
	if(pos==2&&a[3].x-a[2].x==cha)find(a[1].id);
	find(-1);
	return 0;
}