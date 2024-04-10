#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 100010
#define LOGN 18
#define INF 1000000000
using namespace std;

int n;
int ant[MAXN][LOGN];
int altezza[MAXN];
int posizione[MAXN];
vector <int> alt[MAXN];

int antenato(int v,int k){
	for(int i=0;i<LOGN;i++){
		if(k%2)v=ant[v][i];
		k=k>>1;
	}
	return v;
}

void bfs(){
	vector <int> figli[n+1];
	for(int i=1;i<=n;i++)figli[ant[i][0]].push_back(i);
	queue <int> coda;
	coda.push(0);
	altezza[0]=-1;
	while(!coda.empty()){
		int v=coda.front();
		coda.pop();
		posizione[v]=alt[altezza[v]].size();
		alt[altezza[v]].push_back(v);
		for(int i=0;i<int(figli[v].size());i++){
			int f=figli[v][i];
			altezza[f]=altezza[v]+1;
			coda.push(f);
		}
	}
}

int hh,kk,pp;

int sin(int a,int b){
	if(a==b)return a;
	int media=(a+b)/2;
	if(antenato(alt[hh][media],kk)==pp){
		return sin(a,media);
	}
	return sin(media+1,b);
}

int des(int a,int b){
	if(a==b)return a;
	cout.flush();
	int media=(a+b+1)/2;
	if(antenato(alt[hh][media],kk)==pp){
		return des(media,b);
	}
	return des(a,media-1);
}

int main(){
	cin >> n;
	ant[0][0]=0;
	for(int i=1;i<=n;i++)cin >> ant[i][0];
	for(int k=1;k<LOGN;k++)for(int i=0;i<=n;i++)ant[i][k]=ant[ant[i][k-1]][k-1];
	bfs();
	int m;
	cin >> m;
	int res[m];
	int dir[m][2];
	for(int i=0;i<m;i++)cin >>dir[i][0] >> dir[i][1];
	for(int i=0;i<m;i++){
		int v=dir[i][0];
		kk=dir[i][1];
		hh=altezza[v];
		if(hh<kk)res[i]=0;
		else{
			pp=antenato(v,kk);
			int inizio=sin(0,posizione[v]);
			int fine=des(posizione[v],alt[hh].size()-1);
			res[i]=fine-inizio;
		}
	}
	for(int i=0;i<m;i++)cout << res[i] <<" ";
}