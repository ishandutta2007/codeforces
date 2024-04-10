#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 110
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

struct edge{
	int t;
	bool c;
};

bool change[MAXN];
bool fatto[MAXN];
int N,M;
vector <edge> amici[MAXN];

bool dfs(int v){
	fatto[v]=true;
	for(int i=0;i<int(amici[v].size());i++){
		int next=amici[v][i].t;
		bool cc=(amici[v][i].c+change[v]+1)%2;
		if(!fatto[next]){
			change[next]=cc;
			if(dfs(next)==false)return false;
		}
		else if(change[next]!=cc)return false;
	}
	return true;
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int x,y,color;
		cin >> x >> y >> color;
		edge e1,e2;
		e1.t=y;
		e1.c=color;
		e2.t=x;
		e2.c=color;
		amici[x].push_back(e1);
		amici[y].push_back(e2);
	}
	for(int i=1;i<=N;i++){
		if(fatto[i]==false){
			if(dfs(i)==false){
				cout << "Impossible";
				return 0;
			}
		}
	}
	int res=0;
	for(int i=1;i<=N;i++)if(change[i])res++;
	cout << res << "\n";
	for(int i=1;i<=N;i++)if(change[i])cout << i << " ";
}