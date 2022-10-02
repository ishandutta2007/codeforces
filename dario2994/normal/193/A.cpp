#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define INF 2000000000
#define MAXN 52
#define MAXM 52
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;
ifstream in("input.txt");


int X[4]={-1,1,0,0};
int Y[4]={0,0,-1,1};
bool campo[MAXN][MAXM];
int N,M;
int tot;
vector <pair <int,int> > amici[MAXN][MAXM];

void leggi(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		char riga[MAXM];
		cin >> riga;
		for(int j=0;j<M;j++){
			if(riga[j]=='#'){
				campo[i][j]=true;
				tot++;
			}
		}
	}
}

bool dentro(pair <int,int> U){
	int i=U.first;
	int j=U.second;
	if(0<=i and i<N and 0<=j and j<M and campo[i][j])return true;
	return false;
}

void amicizza(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<4;k++){
				pair <int,int> amico=make_pair(i+X[k],j+Y[k]);
				if(dentro(amico))amici[i][j].push_back(amico);
			}
		}
	}
}

bool bfs(int x,int y){
	bool fatto[N][M];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			fatto[i][j]=false;
		}
	}
	queue <pair <int,int> > aperti;
	vector <pair <int,int> > amiconi=amici[x][y];
	int num=amiconi.size();
	if(num==0)return false;
	aperti.push(amiconi[0]);
	num--;
	fatto[amiconi[0].first][amiconi[0].second]=true;
	while(!aperti.empty() and num>0){
		pair <int,int> ora=aperti.front();
		aperti.pop();
		int xx=ora.first;
		int yy=ora.second;
		for(int i=0;i<int(amici[xx][yy].size());i++){
			pair <int,int> ss=amici[xx][yy][i];
			int xxx=ss.first;
			int yyy=ss.second;
			if(fatto[xxx][yyy] or (xxx==x and yyy==y))continue;
			aperti.push(ss);
			fatto[xxx][yyy]=true;
			for(int v=0;v<int(amiconi.size());v++){
				if(amiconi[v]==ss)num--;
			}
		}
	}
	if(num==0)return false;
	else return true;
}

int main(){
	leggi();
	amicizza();
	if(tot<=2){
		cout << -1;
		return 0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(campo[i][j] and bfs(i,j)){
				cout << 1;
				return 0;
			}
		}
	}
	cout << 2;
}