#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 120
#define INF 100000000
using namespace std;
ifstream in("input.txt");

int n;
vector <int> amici[MAXN];
int d1[MAXN];
int dn[MAXN];
bool buono[MAXN];
vector <int> fast[MAXN];
vector <int> slow[MAXN];
double q1[MAXN];
double qn[MAXN];
double q[MAXN];

void bfs1(){
	for(int i=1;i<=n;i++)d1[i]=INF;
	d1[1]=0;
	queue <int> coda;
	coda.push(1);
	while(!coda.empty()){
		int v=coda.front();
		coda.pop();
		for(int i=0;i<int(amici[v].size());i++){
			int a=amici[v][i];
			if(d1[a]<=d1[v]+1)continue;
			d1[a]=d1[v]+1;
			coda.push(a);
		}
	}
}

void bfsn(){
	for(int i=1;i<=n;i++)dn[i]=INF;
	dn[n]=0;
	queue <int> coda;
	coda.push(n);
	while(!coda.empty()){
		int v=coda.front();
		coda.pop();
		for(int i=0;i<int(amici[v].size());i++){
			int a=amici[v][i];
			if(dn[a]<=dn[v]+1)continue;
			dn[a]=dn[v]+1;
			coda.push(a);
		}
	}
}

void bf1(){
	bool aperti[n+1];
	for(int i=1;i<=n;i++)aperti[i]=false;
	q1[1]=1;
	queue <int> coda;
	coda.push(1);
	aperti[1]=true;
	while(!coda.empty()){
		int v=coda.front();
		coda.pop();
		for(int i=0;i<int(fast[v].size());i++){
			int a=fast[v][i];
			q1[a]+=q1[v];
			if(aperti[a])continue;
			aperti[a]=true;
			coda.push(a);
		}
	}
}

void bfn(){
	bool aperti[n+1];
	for(int i=1;i<=n;i++)aperti[i]=false;
	qn[n]=1;
	queue <int> coda;
	coda.push(n);
	aperti[n]=true;
	while(!coda.empty()){
		int v=coda.front();
		coda.pop();
		for(int i=0;i<int(slow[v].size());i++){
			int a=slow[v][i];
			qn[a]+=qn[v];
			if(aperti[a])continue;
			aperti[a]=true;
			coda.push(a);
		}
	}
}

int main(){
	int m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		amici[x].push_back(y);
		amici[y].push_back(x);
	}
	bfs1();
	bfsn();
	//for(int i=1;i<=n;i++)cout << i << ": " << d1[i] << ", " << dn[i] << endl; 
	int minimo=INF;
	for(int i=1;i<=n;i++)minimo=min(minimo,d1[i]+dn[i]);
	for(int i=1;i<=n;i++)if(d1[i]+dn[i]==minimo)buono[i]=true;
	for(int v=1;v<=n;v++){
		if(!buono[v])continue;
		for(int i=0;i<int(amici[v].size());i++){
			int a=amici[v][i];
			if(!buono[a])continue;
			if(d1[v]+dn[a]+1==minimo)fast[v].push_back(a);
			if(d1[a]+dn[v]+1==minimo)slow[v].push_back(a);
		}
	}
	bf1();
	bfn();
	//~ for(int i=1;i<=n;i++){
		//~ cout << i << ": ";
		//~ for(int e=0;e<int(slow[i].size());e++)cout << slow[i][e] << " ";
		//~ cout << endl;
	//~ }
	//~ for(int i=1;i<=n;i++)cout << i << " " << q1[i] << endl;
	for(int i=1;i<=n;i++)q[i]=q1[i]*qn[i];
	double maxx=1;
	for(int i=2;i<n;i++)maxx=max(maxx,2*q[i]/q[1]);
	cout.precision(100);
	cout << maxx;
}