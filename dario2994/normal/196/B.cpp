#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <tr1/unordered_map>
#define INF 2000000000
#define MAXN 5000
#define MAXM 5000
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;
using namespace tr1;
ifstream in("input.txt");

int N,M;
char cosa[MAXN][MAXM];
pair <int,int> S;
int X[4]={1,-1,0,0};
int Y[4]={0,0,-1,1};
int quadri=0;

int mod(int a,int b){
	a=a%b;
	if(a<0)a+=b;
	return a;
}

void leggi(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		char riga[M+3];
		scanf("%s",riga);
		//in >> riga;
		for(int j=0;j<M;j++){
			if(riga[j]=='S')S=make_pair(i,j);
			if(riga[j]!='#'){
				quadri++;
				cosa[i][j]=true;
			}
		}
	}
}

LL hashi(LL u,LL v){
	return u*10000000+v;
}

bool dfs(){
	//set <pair <int,int> > fatto;
	unordered_map <ULL ,bool> fatto;
	stack <pair <int,int> > aperti;
	aperti.push(S);
	while(!aperti.empty() and int(fatto.size())<quadri+5){
		pair <int,int> V=aperti.top();
		aperti.pop();
		int x=V.first;
		int y=V.second;
		
		for(int i=0;i<4;i++){
			//if(cosa[mod(x+X[i],N)][mod(y+Y[i],M)] and fatto.insert(make_pair(x+X[i],y+Y[i])).second){
			if(cosa[mod(x+X[i],N)][mod(y+Y[i],M)] and !fatto[hashi(x+X[i],y+Y[i])]){
				fatto[hashi(x+X[i],y+Y[i])]=true;
				aperti.push(make_pair(x+X[i],y+Y[i]));
			}
		}
	}
	if(int(fatto.size())>quadri+3)return true;
	return false;
}

int main(){
	leggi();
	bool res=dfs();
	if(res)cout << "Yes\n";
	else cout << "No\n";
}