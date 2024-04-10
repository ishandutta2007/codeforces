#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n;
int xx[1010];
int yy[1010];
vector <int> amici[120];
bool fatto[120];
int comp=0;

void dfs(int v){
	for(int i=0;i<int(amici[v].size());i++){
		int a=amici[v][i];
		if(fatto[a])continue;
		fatto[a]=true;
		dfs(a);
	}
}

int main(){
	cin >> n;
	for(int i=0;i<1005;i++){
		xx[i]=-1;
		yy[i]=-1;
	}
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		if(xx[x]==-1)xx[x]=i;
		else{
			amici[i].push_back(xx[x]);
			amici[xx[x]].push_back(i);
		}
		if(yy[y]==-1)yy[y]=i;
		else{
			amici[i].push_back(yy[y]);
			amici[yy[y]].push_back(i);
		}
	}
	for(int i=0;i<n;i++){
		if(!fatto[i]){
			comp++;
			fatto[i]=true;
			dfs(i);
		}
	}
	cout << comp-1;
}