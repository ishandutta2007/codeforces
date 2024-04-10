#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 100010
#define INF 1000000000
using namespace std;

int n,k;
bool ll[MAXN];
bool rr[MAXN];
vector <int> amici[MAXN*2];
int tempo[2*MAXN];

bool in(int x){
	if(0<=x and x<n)return true;
	return false;
}

bool bfs(){
	for(int i=0;i<=2*n;i++)tempo[i]=INF;
	tempo[1]=0;
	queue <int> coda;
	coda.push(1);
	while(!coda.empty()){
		int v=coda.front();
		coda.pop();
		int t=tempo[v];
		for(int i=0;i<int(amici[v].size());i++){
			int a=amici[v][i];
			if(a==0)return true;
			if(tempo[a]<=t+1)continue;//gi in coda o gi eseguito
			if(t+1>=(a%n) and (a%n!=0))continue;
			tempo[a]=t+1;
			coda.push(a);
		}
	}
	return false;
}

int main(){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		char x;
		cin >> x;
		if(x=='-')ll[i]=true;
		else ll[i]=false;
	}
	for(int i=0;i<n;i++){
		char x;
		cin >> x;
		if(x=='-')rr[i]=true;
		else rr[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!ll[i])continue;
		if(in(i+1) and ll[i+1]){
			amici[i+1].push_back(i+2);
			amici[i+2].push_back(i+1);
		}
		if(!in(i+k)){
			amici[i+1].push_back(0);
			amici[0].push_back(i+1);
		}
		else if(rr[i+k]){
			amici[i+1].push_back(n+1+i+k);
			//amici[n+1+i+k].push_back(i+1);
		}
	}
	for(int i=0;i<n;i++){
		if(!rr[i])continue;
		if(in(i+1) and rr[i+1]){
			amici[n+1+i].push_back(n+1+i+1);
			amici[n+1+i+1].push_back(n+1+i);
		}
		if(!in(i+k)){
			amici[n+1+i].push_back(0);
			amici[0].push_back(n+1+i);
		}
		else if(ll[i+k]){
			amici[n+1+i].push_back(1+i+k);
			//amici[1+i+k].push_back(n+1+i);
		}
	}
	//~ for(int i=0;i<=2*n;i++){
		//~ cout << i << ": ";
		//~ for(int u=0;u<int(amici[i].size());u++)cout << amici[i][u] << " ";
		//~ cout << endl;
	//~ }
	//~ bfs();
	//~ for(int i=0;i<2*n+1;i++)cout << i << " " << tempo[i] << endl;
	if(bfs())cout << "YES";
	else cout << "NO";
}