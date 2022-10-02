#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#define MAXN 100010
typedef long long LL;
using namespace std;

int n;

vector <int> vicini[MAXN];
vector <int> nnn[MAXN];

int quanti[MAXN];

vector <int> figli[MAXN];
vector <int> number[MAXN];
int ant[MAXN][20];
int h[MAXN];

int ris[MAXN];

void build(int v,int pp){
	//cout << v << " " << pp <<  endl;
	ant[v][0]=pp;
	h[v]=h[pp]+1;
	for(int i=0;i<int(vicini[v].size());i++){
		int ff=vicini[v][i];
		if(ff==pp)continue;
		else{
			figli[v].push_back(ff);
			number[v].push_back(nnn[v][i]);
			build(ff,v);
		}
	}
}

void preprocess(){
	for(int i=0;i<=18;i++){
		for(int v=1;v<=n;v++)ant[v][i+1]=ant[ant[v][i]][i];
	}
}

int antenato(int v,int l){
	int pot=0;
	while(l>0){
		if(l%2==1)v=ant[v][pot];
		l/=2;
		pot++;
	}
	return v;
}

int lca(int u,int v){
	
	if(h[u]>h[v]){
		u=antenato(u,h[u]-h[v]);
	}
	if(h[u]<h[v]){
		v=antenato(v,h[v]-h[u]);
	}
	if(u==v)return u;
	for(int i=19;i>=0;i--){
		//cout << u << " " << v << endl;
		if(ant[u][i]!=ant[v][i]){
			u=ant[u][i];
			v=ant[v][i];
		}
	}
	return ant[u][0];
}

int riss(int v){
	int xx=0;
	for(int i=0;i<int(figli[v].size());i++){
		int ff=figli[v][i];
		ris[number[v][i]]=riss(ff);
		xx+=ris[number[v][i]];
	}
	xx+=quanti[v];
	//cout << v << " " << xx << endl;
	return xx;
}

int main(){
	//~ ifstream in("input.txt");
	cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		vicini[x].push_back(y);
		vicini[y].push_back(x);
		nnn[x].push_back(i);
		nnn[y].push_back(i);
	}
	build(1,0);
	preprocess();
	//~ for(int v=1;v<=5;v++){
		//~ cout << v << ": ";
		//~ for(int i=0;i<3;i++)cout << ant[v][i] << " ";
		//~ cout << endl;
	//~ }
	//~ for(int i=1;i<=n;i++){
		//~ for(int j=1;j<=n;j++){
			//~ cout << i << " " << j << "= " << lca(i,j)<< endl;
		//~ }
	//~ }
	int k;
	cin >> k;
	for(int i=0;i<k;i++){
		int u,v;
		cin >> u >> v;
		quanti[u]++;
		quanti[v]++;
		quanti[lca(u,v)]-=2;
	}
	//for(int i=1;i<=5;i++)cout << quanti[i] << endl;
	riss(1);
	for(int i=0;i<n-1;i++)cout << ris[i] << " ";
}