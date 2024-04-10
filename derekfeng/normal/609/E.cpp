#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int Maxn=200005;
const int Maxm=21;
int n,m;
int A[Maxn],B[Maxn],C[Maxn];
vector <iii> E;
int par[Maxn],siz[Maxn];
ll res;
vector <ii> neigh[Maxn];
int L[Maxn],P[Maxn][Maxm],W[Maxn][Maxm];
int getPar(int x){return par[x]==x?x:par[x]=getPar(par[x]);}
bool unionSet(int a,int b){
	a=getPar(a),b=getPar(b);
	if (a==b) return false;
	if (siz[a]>=siz[b]){siz[a]+=siz[b];par[b]=a;}
	else{siz[b]+=siz[a];par[a]=b;}
	return true;
}
void Traverse(int v){
	for (int i=0;i<neigh[v].size();i++){
		ii u=neigh[v][i];
		if (P[v][0]==u.first) continue;
		L[u.first]=L[v]+1;
		P[u.first][0]=v;W[u.first][0]=u.second;
		Traverse(u.first);
	}
}
int getMax(int a,int b){
	if (L[a]<L[b]) swap(a,b);
	int res=0;
	for (int i=Maxm-1;i>=0;i--)
		if (L[a]-(1 << i)>=L[b]){
			res=max(res,W[a][i]);
			a=P[a][i];
		}
	if (a==b) return res;
	for (int i=Maxm-1;i>=0;i--)
		if (P[a][i]!=P[b][i]){
			res=max(res,max(W[a][i],W[b][i]));
			a=P[a][i],b=P[b][i];
		}
	res=max(res,max(W[a][0],W[b][0]));
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&A[i],&B[i],&C[i]);
		E.push_back(iii(C[i],ii(A[i],B[i])));
	}
	sort(E.begin(),E.end());
	for (int i=1;i<=n;i++)
		par[i]=i,siz[i]=1;
	for (int i=0;i<E.size();i++){
		int a=E[i].second.first,b=E[i].second.second;
		if (unionSet(a,b)){
			res+=E[i].first;
			neigh[a].push_back(ii(b,E[i].first));
			neigh[b].push_back(ii(a,E[i].first));
		}
	}
	Traverse(1);
	for (int j=1;j<Maxm;j++)
		for (int i=1;i<=n;i++){
			P[i][j]=P[P[i][j-1]][j-1];
			W[i][j]=max(W[i][j-1],W[P[i][j-1]][j-1]);
		}
	for (int i=0;i<m;i++){
		int mx=getMax(A[i],B[i]);
		printf("%I64d\n",res-ll(mx)+ll(C[i]));
	}
	return 0;
}