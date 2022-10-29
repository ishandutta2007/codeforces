#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 100005
#define mkp(a,b) make_pair(a,b)
using namespace std;

int n,m,i,j,k,a[maxn][2],id[2][maxn],tot,p[maxn][3];
map<pair<int,int>,int> S; 
int cmp1(int i,int j){return a[i][0]<a[j][0];}
int cmp2(int i,int j){return a[i][1]<a[j][1];}

void add(int x,int y,int r){
	tot++,p[tot][0]=x,p[tot][1]=y,p[tot][2]=r;
}

int Find(int x,int y){
	int l=1,r=tot,mid=0,id=0;
	while (l<=r){
		mid=(l+r)>>1;
		if (p[mid][0]<=x) id=mid,l=mid+1;
		else r=mid-1;
	}
	if (!id) return 0;
	return x<p[id][0]+p[id][2]&&y-x==p[id][1]-p[id][0];
}

int get(int x,int y){
	return S.find(mkp(x,y))!=S.end()||Find(x,y);
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i][0],&a[i][1]);
		S[mkp(a[i][0],a[i][1])]=1;
		id[0][i]=id[1][i]=i;
	}
	sort(id[0]+1,id[0]+1+n,cmp1);
	sort(id[1]+1,id[1]+1+n,cmp2);
	static int x[2],I[2]; x[0]=x[1]=0,I[0]=I[1]=1;
	while (I[0]<=n||I[1]<=n){
		int t; 
		if (I[0]>n) t=1; else if (I[1]>n) t=0; 
		else t=a[id[0][I[0]]][0]-x[0]>a[id[1][I[1]]][1]-x[1];
		if (a[id[t][I[t]]][t^1]-x[t^1]>a[id[t][I[t]]][t]-x[t]) {I[t]++;continue;}
		if (a[id[t][I[t]]][t]<x[t]) {I[t]++;continue;}
		if (a[id[t][I[t]]][t]==x[t]) {
			x[t]++,x[t^1]+=a[id[t][I[t]]][t^1]==x[t^1];
			I[t]++;
			continue;
		}
		add(x[0],x[1],a[id[t][I[t]]][t]-x[t]);
		k=a[id[t][I[t]]][t]-x[t];
		x[0]+=k,x[1]+=k;
		if (x[0]==a[id[t][I[t]]][0]) x[0]++;
		if (x[1]==a[id[t][I[t]]][1]) x[1]++;
		I[t]++;
	}
	add(x[0],x[1],1e9);
//	for(i=0;i<=m;i++,putchar('\n')) for(j=0;j<=m;j++)
//		printf("%d",get(i,j)^1);
	for(i=1;i<=m;i++) {
		int xx,yy; 
		scanf("%d%d",&xx,&yy);
		if (get(xx,yy)) printf("LOSE\n"); else printf("WIN\n");
	}
}