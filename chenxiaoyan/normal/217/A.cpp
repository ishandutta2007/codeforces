#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int x[N+1],y[N+1];
int fa[N+1];
int root(int p){return fa[p]==p?p:fa[p]=root(fa[p]);}
void merge(int p,int q){fa[root(p)]=root(q);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
		for(int j=1;j<i;j++)if(x[i]==x[j]||y[i]==y[j])merge(i,j);
	}
	int ans=-1;
	for(int i=1;i<=n;i++)if(fa[i]==i)ans++;
	printf("%d",ans);
	return 0;
}
/*1
2
2 1
1 2
*/
/*2
2
2 1
4 1
*/