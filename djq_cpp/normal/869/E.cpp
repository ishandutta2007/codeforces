#include <bits/stdc++.h>
#define rep1(k,n) for(int k=1;k<=n;k++)
using namespace std;
int n,m;
int HA[2505][2505];
inline int lowbit(int x){
	return x&-x;
}
int tre[2505][2505];
void modify(int x,int y,int v){
	int cx=x,cy;
	while(cx>0){
		cy=y;
		while(cy>0){
			tre[cx][cy]+=v;
			cy-=lowbit(cy);
		}
		cx-=lowbit(cx);
	}
}
void modify(int x1,int y1,int x2,int y2,int v){
	x1--;y1--;
	modify(x1,y1,v);
	modify(x2,y2,v);
	modify(x1,y2,-v);
	modify(x2,y1,-v);
}
int query(int x,int y){
	int cx=x,cy;
	int ans=0;
	while(cx<=n){
		cy=y;
		while(cy<=m){
			ans+=tre[cx][cy];
			cy+=lowbit(cy);
		}
		cx+=lowbit(cx);
	}
	return ans;
}
int main(){
	int q,t,x1,y1,x2,y2;
	scanf("%d%d%d",&n,&m,&q);
	rep1(i,n)rep1(j,m)HA[i][j]=rand()*rand()+rand();
	rep1(k,q){
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		if(t==1)modify(x1,y1,x2,y2,HA[x1][y1]);
		else if(t==2)modify(x1,y1,x2,y2,-HA[x1][y1]);
		else printf(query(x1,y1)==query(x2,y2)?"Yes\n":"No\n");
	}
	return 0;
}