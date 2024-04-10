#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int deep[MAXN];
vector<int> E[MAXN];
int father[MAXN][20];
int n,q;
void build (int nod,int fa,int depth){
	deep[nod] = depth;
	for (vector<int>::iterator it = E[nod].begin();it!=E[nod].end();it++){
		if ((*it)!=fa){
			father[*it][0] = nod;
			build (*it,nod,depth+1);
		}
	}
}
void initLCA(){
	for (int i=1;i<=19;i++){
		for (int j = 1;j<=n;j++){
			father[j][i] = father[father[j][i-1]][i-1];
		}
	}
}
int lca(int a,int b){
	if (deep[a]<deep[b]){
		swap(a,b);
	}
	for (int i=19;i>=0;i--){
		if (deep[father[a][i]]>=deep[b]){
			a = father[a][i];
		}
	}
	if (a==b){
		return a;
	}
	for (int i=19;i>=0;i--){
		if (father[a][i]!=father[b][i]){
			a = father[a][i];
			b = father[b][i];
		}
	}
	return father[a][0];
}
int length (int a,int b){
	int anc = lca (a,b);
	return (deep[a]+deep[b]-2*deep[anc]);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++){
		int temp;
		scanf("%d",&temp);
		E[temp].push_back(i);
		E[i].push_back(temp);
	}
	build (1,0,1);
	initLCA();
//	for (int i = 1;i<=n;i++){
//		cout<<"deep["<<i<<"]="<<deep[i]<<endl;
//	}
	while (q--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int anc1 = lca(a,b);
		int anc2 = lca(a,c);
		int anc3 = lca(b,c);
		if (deep[anc2]>deep[anc1]){
			anc1 = anc2;
		}
		if (deep[anc3]>deep[anc1]){
			anc1 = anc3;
		}
		int ans1 = length(anc1,a);
		int ans2 = length(anc1,b);
		int ans3 = length(anc1,c);
		int ans = max (max ( ans1,ans2),ans3)+1;
		printf("%d\n",ans);
	}
	return 0;
}