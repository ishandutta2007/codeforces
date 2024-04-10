#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define INF 2000000000
#define MAXN 5010
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;
int N;
vector <int> a[MAXN];
vector <int> tot[MAXN];
bool possibili[MAXN];

void genera(vector <int> num){
	bool possible[N];
	possible[0]=true;
	for(int i=1;i<N;i++)possible[i]=false;
	for(int i=0;i<int(num.size());i++){
		int t=num[i];
		vector <int> aggiunti;
		for(int j=0;j<N-t;j++){
			if(possible[j])aggiunti.push_back(j+t);
		}
		for(int j=0;j<int(aggiunti.size());j++)possible[aggiunti[j]]=true;
	}
	//~ for(int i=1;i<N-1;i++){
		//~ if(possible[i])cout << i << endl;
	//~ }
	for(int i=1;i<N-1;i++){
		if(possible[i])possibili[i]=true;
	}
}

int dfs(int v,int padre){
	//cout << v << endl;
	vector <int> valori;
	int somma=0;
	for(int i=0;i<int(a[v].size());i++){
		int amico=a[v][i];
		if(amico==padre)continue;
		int ris=dfs(amico,v)+1;
		valori.push_back(ris);
		somma+=ris;
	}
	valori.push_back(N-1-somma);
	genera(valori);
	return somma;
}
int main(){
	//~ int M;
	//~ cin >> M;
	//~ vector <int> pop;
	//~ for(int i=0;i<M;i++){
		//~ int x;
		//~ cin >> x;
		//~ pop.push_back(x);
	//~ }
	//~ cin >> N;
	//~ genera(pop);
	cin >> N;
	if(N<=2)cout << 0;
	for(int i=0;i<N-1;i++){
		int x,y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	//cout << "yo";
	//cout.flush();
	dfs(1,0);
	vector <int> scelte;
	for(int i=1;i<N-1;i++){
		if(possibili[i])scelte.push_back(i);
	}
	cout << scelte.size()<<endl;
	for(int i=0;i<int(scelte.size());i++){
		cout << scelte[i] << " " << N-1-scelte[i] << endl;
	}
}