#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAXN 100010
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL MOD=1e9+7;
int root[MAXN];//un successore di i
LL peso[MAXN];//peso da i a root[i]

void scopri(int x){//mette root[x] e peso[x] giusti
	if(root[x]==x)return;
	scopri(root[x]);
	peso[x]=(peso[x]+peso[root[x]])%MOD;
	root[x]=root[root[x]];
}

int main(){
	int N;
	cin >> N;
	LL res=0;
	for(int v=1;v<=N;v++){
		root[v]=v;
		peso[v]=0;
		int k;
		cin >> k;
		for(int i=0;i<k;i++){
			int u;
			LL p;
			cin >> u >> p;
			scopri(u);
			res=(res+p+peso[u])%MOD;
			peso[root[u]]=(p+peso[u])%MOD;
			root[root[u]]=v;
		}
	}
	if(res<0)res+=MOD;
	cout << res;
}