#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+50,M=5e5+50;
struct node{
	int l,r;
	bool friend operator <(node a,node b){
		return a.l<b.l;
	}
}a[N];
int n,m,minn=1e9,maxn=-1e9,f[20][M],x,y,max_i;
int ask(int x,int y){
	int ret=0;
	for(int i=max_i;i>=0;i--)
		if(f[i][x]<y)x=f[i][x],ret+=(1<<i);
	if(f[0][x]>=y)return ret+1;
	return -1;
}
int main(){
	scanf("%d%d",&n,&m);     
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		maxn=max(maxn,a[i].r);
	}
	sort(a+1,a+n+1);minn=a[1].l;
	for(int i=minn,j=0,mm=-1e9;i<=maxn;i++){
		while(j<n&&a[j+1].l<=i)mm=max(mm,a[++j].r);
		f[0][i]=mm;
	}
	max_i=log2(n);
	for(int i=1;i<=max_i;i++)
		for(int j=minn;j<=maxn;j++)
			f[i][j]=f[i-1][f[i-1][j]];
	while(m--){
		scanf("%d%d",&x,&y);
		printf("%d\n",ask(x,y));
	}
	return 0;
}