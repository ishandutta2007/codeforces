#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 100010
using namespace std;

int N;
vector <int> aa[MAXN];
int tipo[MAXN];

int sotto[MAXN];
void sottezza(int v, int p){
	sotto[v]=1;
	for(int i=0;i<int(aa[v].size());i++){
		int a=aa[v][i];
		if(a==p or tipo[a]>0)continue;
		sottezza(a, v);
		sotto[v]+=sotto[a];
	}
}

int K;
int trova(int v, int p){
	for(int i=0;i<int(aa[v].size());i++){
		int a=aa[v][i];
		if(a==p or tipo[a]>0)continue;
		if(sotto[a]>K/2)return trova(a, v);
	}
	return v;
}

int centro(int v){
	sottezza(v, -1);
	K=sotto[v];
	return trova(v, -1);
}

void risolvi(int v, int l){
	int u=centro(v);
	tipo[u]=l;
	for(int i=0;i<int(aa[u].size());i++){
		int a=aa[u][i];
		if(tipo[a]==0)risolvi(a, l+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		aa[a].push_back(b);
		aa[b].push_back(a);
	}
	risolvi(1,1);
	for(int i=1;i<=N;i++)cout << char('A'+tipo[i]-1) << " ";
	cout << "\n";
}