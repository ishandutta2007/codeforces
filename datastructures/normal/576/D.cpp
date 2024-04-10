#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
#define inf 1111111111
using namespace std;
int n,m,ans=inf;
struct node{
	int a,b,d;
}c[155];
bool cmp(node a,node b){
	return a.d<b.d;
}
struct Mat{
	bitset<155> mat[155];
	Mat(){
		memset(mat,0,sizeof(mat));
		return;
	}
	Mat operator *(const Mat &x)const{
		Mat ans;
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				if (mat[i][k])ans.mat[i]|=x.mat[k];
		return ans;
	}
}now,x;
Mat Qpow(Mat a,int p){
	if (p==1)return a;
	Mat t=Qpow(a,p/2);
	t=t*t;
	if (p%2==1)t=t*a;
	return t; 
}
int q[155],head,tail,dis[155];
int bfs(){
	for (int i=1;i<=n;i++)dis[i]=inf;
	head=1,tail=0;
	for (int i=1;i<=n;i++)
		if (now.mat[1][i]==1)dis[i]=0,q[++tail]=i;
	while(head<=tail){
		int now=q[head];
		head++;
		for (int i=1;i<=n;i++)
			if (x.mat[now][i]==1&&dis[i]==inf){
				dis[i]=dis[now]+1;
				q[++tail]=i;
			}
	}
	return dis[n];
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++)cin>>c[i].a>>c[i].b>>c[i].d;
	sort(c+1,c+1+m,cmp);
	now.mat[1][1]=1;
	for (int i=1;i<=m;i++){
		if (c[i].d>c[i-1].d)now=now*Qpow(x,c[i].d-c[i-1].d);
		x.mat[c[i].a][c[i].b]=1;
		ans=min(ans,c[i].d+bfs());
	}
	if (ans<inf)cout<<ans<<endl;
	else puts("Impossible");
	return 0;
}