#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#define MAXN 500010
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
ifstream in("input.txt");

int n;
vector <int> aa[MAXN];
vector <int> tip[MAXN];
int costo[MAXN];

int dfs1(int v,int p){
	int res=0;
	for(int i=0;i<int(aa[v].size());i++){
		int a=aa[v][i];
		if(a==p)continue;
		res+=dfs1(a,v);
		res+=tip[v][i];
	}
	return res;
}

void dfs2(int v,int p){
	for(int i=0;i<int(aa[v].size());i++){
		int a=aa[v][i];
		if(a==p)continue;
		if(tip[v][i]==0)costo[a]=costo[v]+1;
		else costo[a]=costo[v]-1;
		dfs2(a,v);
	}
}

int main(){
	cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		aa[x].push_back(y);
		tip[x].push_back(0);
		aa[y].push_back(x);
		tip[y].push_back(1);
	}
	costo[1]=dfs1(1,0);
	dfs2(1,0);
	//~ for(int i=1;i<=n;i++) cout << i << ": " << costo[i] << endl;
	int minimo=INF;
	for(int i=1;i<=n;i++)minimo=min(minimo,costo[i]);
	cout << minimo << endl;
	for(int i=1;i<=n;i++)if(costo[i]==minimo)cout << i << " ";
}