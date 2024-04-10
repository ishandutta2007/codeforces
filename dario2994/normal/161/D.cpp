#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAXM int(1<<14)
#define MAXN 50010
#define MAXK 510
typedef long long LL;

using namespace std;

int N,k;
vector <int> amico[MAXN];
int val[MAXN][MAXK];
LL ris[MAXN];

void dfs(int v,int p){
	for(int i=0;i<int(amico[v].size());i++){
		int a=amico[v][i];
		if(a==p)continue;
		dfs(a,v);
	}
	val[v][0]=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<int(amico[v].size());j++){
			int a=amico[v][j];
			if(a==p)continue;
			val[v][i]+=val[a][i-1];
		}
	}
	LL res=0;
	for(int i=1;i<k;i++){
		for(int j=0;j<int(amico[v].size());j++){
			int a=amico[v][j];
			if(a==p)continue;
			res+=LL(val[a][i-1])*LL(val[v][k-i]-val[a][k-i-1]);
		}
	}
	res/=2;
	for(int j=0;j<int(amico[v].size());j++){
		int a=amico[v][j];
		if(a==p)continue;
		res+=val[a][k-1];
	}
	ris[v]=res;
}

int main(){
	cin >> N >> k;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		amico[a].push_back(b);
		amico[b].push_back(a);
	}
	dfs(1,0);
	LL tot=0;
	for(int i=1;i<=N;i++)tot+=ris[i];
	cout << tot;
}