typedef unsigned long long ULL;
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <queue>
#define MAXN 100010
#define MAXM 100010
#define mod 1000000007
using namespace std;

int N,M;
pair <int,int> edge[MAXM];
vector <int> amici[MAXN];
vector <int> arc[MAXN];
int label[MAXN];
bool ciclo[MAXN];
int ant[MAXN][18];
int prefix[MAXN];
int height[MAXN];

void dfs(int v,int p){
	//~ cout << v << " " << p << endl;
	label[v]=v;
	for(int i=0;i<int(amici[v].size());i++){
		int a=amici[v][i];
		if(a==p)continue;
		if(label[a]!=0){
			label[v]=label[a];
			continue;
		}
		dfs(a,v);
		if(label[a]!=a)label[v]=label[a];
	}
}

void antenata(){
	for(int j=1;j<=17;j++)for(int i=1;i<=N;i++)if(i==label[i])ant[i][j]=ant[ant[i][j-1]][j-1];
}

void tuttizza(int v,int p){
	prefix[v]=prefix[p]+int(ciclo[v]);
	height[v]=height[p]+1;
	ant[v][0]=p;
	for(int i=0;i<int(arc[v].size());i++){
		int a=arc[v][i];
		if(a==p)continue;
		tuttizza(a,v);
	}
}

int antenato(int v,int k){
	for(int i=0;i<=17;i++){
		if(k&1)v=ant[v][i];
		k>>=1;
	}
	return v;
}

int lca(int a,int b){
	if(height[a]>height[b])a=antenato(a,height[a]-height[b]);
	else b=antenato(b,height[b]-height[a]);
	if(a==b)return a;
	for(int i=17;i>=0;i--){
		if(ant[a][i]!=ant[b][i]){
			a=ant[a][i];
			b=ant[b][i];
		}
	}
	return ant[a][0];
}

ULL pot(ULL a,int e){
	if(e==0)return 1;
	if(e%2)return (a*pot((a*a)%mod,e>>1))%mod;
	else return pot((a*a)%mod,e>>1);
}

int main(){
	ios_base::sync_with_stdio(false);
	//~ ifstream in("input.txt");
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		amici[x].push_back(y);
		amici[y].push_back(x);
		edge[i]=make_pair(x,y);
	}
	dfs(1,1);
	//~ for(int i=1;i<=N;i++)cout << i << " " << label[i] << endl;
	for(int i=1;i<=N;i++)if(label[i]!=i)ciclo[label[i]]=true;
	for(int i=0;i<M;i++){
		int x=label[edge[i].first];
		int y=label[edge[i].second];
		if(x!=y){
			arc[x].push_back(y);
			arc[y].push_back(x);
		}
	}
	tuttizza(1,1);
	antenata();
	//~ for(int i=1;i<=N;i++)if(i==label[i])cout << i << " " << prefix[i]<< endl;
	//~ cout << lca(9,8);
	int t;
	cin >> t;
	int res[t];
	for(int i=0;i<t;i++){
		int a,b;
		cin >> a >> b;
		int A=label[a];
		int B=label[b];
		int C=lca(A,B);
		//~ cout << A << " " << B << " " << C << endl;
		int E=prefix[A]+prefix[B]-2*prefix[C]+int(ciclo[C]);
		res[i]=pot(2,E);
	}
	for(int i=0;i<t;i++)cout << res[i] << "\n";
}