#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int n,m,pos[200005],a,b,fa[200005],size[200005],val[200005],ans;
vector <int>c[200005];
map <int,int>d[200005];
inline int find(int x){
	if (x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
inline void ins(int a,int b){
	d[a][b]++;
	val[a]++;
	if (d[a][b-1]==1)val[a]--;
	if (d[a][b+1]==1)val[a]--;
	return;
} 
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a);
		if (pos[a]==0)pos[a]=i;
		fa[i]=pos[a];
		size[pos[a]]++;
		ins(pos[a],i);
		c[pos[a]].push_back(i);
	}
	for (int i=1;i<=n;i++)ans+=val[i];
	printf("%d\n",ans-1);
	for (int i=1;i<m;i++){
		scanf("%d%d",&a,&b);
		int xa=find(pos[a]),xb=find(pos[b]);
		if (size[xa]<size[xb])swap(xa,xb),pos[a]=pos[b];
		a=xa,b=xb;
		fa[b]=a;
		ans-=val[a]+val[b];
		for (int j=0;j<size[b];j++)
			c[a].push_back(c[b][j]),ins(a,c[b][j]);
		ans+=val[a];
		size[a]+=size[b],size[b]=0;
		printf("%d\n",ans-1);
	}
	return 0;
}