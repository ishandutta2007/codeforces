#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define MAXN 100010
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

set <pair <int,int> > buoni;
//~ pair <int,int> ok[MAXN];
//~ bool aperto[MAXN];

int main(){
	pair <int,int> inizio;
	pair <int,int> fine;
	cin >> inizio.second >> inizio.first >> fine.second >> fine.first;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int r,a,b;
		cin >> r >> a >> b;
		pair <int,int> nuovo;
		nuovo.second=r;
		for(int j=a;j<=b;j++){
			//~ cout << "YE";
			nuovo.first=j;
			buoni.insert(nuovo);
		}
	}
	queue <pair <pair <int,int>,int> > coda;
	buoni.erase(inizio);
	coda.push(make_pair(inizio,0));
	while(!coda.empty()){
		pair < pair <int,int>,int> act=coda.front();
		coda.pop();
		pair <int,int> punto=act.first;
		int t=act.second;
		if(punto==fine){
			cout << t;
			return 0;
		}
		for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++){
			pair <int,int> nuovo=make_pair(punto.first+i,punto.second+j);
			//~ cout << "YO" << "\n";
			if(buoni.find(nuovo)!=buoni.end()){
				buoni.erase(nuovo);
				coda.push( make_pair(nuovo,t+1) );
			}
		}
	}
	cout << -1;
}