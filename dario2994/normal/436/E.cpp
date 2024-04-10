#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#define MAXN 300010
using namespace std;

int INF=2*1e9+5;
int N,w;
int a[MAXN], b[MAXN];
vector <pair <int , pair <int,short int> > > proc;
int risultato[MAXN];



long long tipo1() {
	for(int i=0;i<N;i++) risultato[i]=0;
	int quanti=0;
	int it=0;
	long long tempo=0;
	while( quanti<w and quanti + proc[it].second.second <= w ) {
		quanti+=proc[it].second.second;
		tempo+=((long long)(proc[it].first))*((long long)(proc[it].second.second));
		risultato[proc[it].second.first]+=proc[it].second.second;
		it++;
	}
	if( quanti < w ) {
		int migliore=-1;
		int valore=INF;
		for(int i=0;i<N;i++) {
			int ttt=INF;
			if( risultato[i]==0 ) ttt=2*a[i];
			else if( risultato[i]==1 ) ttt=2*(b[i]-a[i]);
			
			if( valore > ttt ) valore=ttt, migliore=i;
		}
		tempo+=(long long)valore;
		risultato[migliore]++;
	}
	return tempo;
}

long long tipo2() {
	for(int i=0;i<N;i++) risultato[i]=0;
	int quanti=0;
	int it=0;
	long long tempo=0;
	while( quanti<w+1 and quanti + proc[it].second.second <= w+1 ) {
		quanti+=proc[it].second.second;
		tempo+=((long long)(proc[it].first))*((long long)(proc[it].second.second));
		risultato[proc[it].second.first]+=proc[it].second.second;
		it++;
	}
	if( quanti==w+1 ) { //ne posso togliere 1 (quanti  w oppure w+1) ok
		int migliore=-1;
		int valore=-INF;
		for(int i=0;i<N;i++) {
			int ttt=-INF;
			if( risultato[i]==1 ) ttt=2*a[i];
			else if( risultato[i]==2 ) ttt=2*(b[i]-a[i]);
			
			if( valore < ttt ) valore=ttt, migliore=i;
		}
		tempo-=(long long)valore;
		risultato[migliore]--;
	}
	return tempo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> w;
	for(int i=0;i<N;i++) cin >> a[i] >> b[i];
	for(int i=0;i<N;i++) {
		if( a[i]<=b[i]-a[i] ) {
			proc.push_back(make_pair(2*a[i],make_pair(i,1)));
			proc.push_back(make_pair(2*(b[i]-a[i]),make_pair(i,1)));
		}
		else{
			proc.push_back(make_pair(b[i],make_pair(i,2)));
		}
	}
	//~ for(int i=0;i<(int)proc.size();i++) cout << proc[i].first.first << " " << proc[i].second.first << " " << proc[i].second.second << "\n";
	sort(proc.begin(), proc.end());
	//~ cout << "\n";
	//~ for(int i=0;i<(int)proc.size();i++) cout << proc[i].first.first << " " << proc[i].second.first << " " << proc[i].second.second << "\n";
	//~ for(int i=0;i<(int)proc.size();i++) cout << proc[i].second.first << " " << proc[i].second.second << "\n";
	
	long long tempo=0;
	if( w==2*N ) tempo=tipo1();
	else {
		if( tipo1()<tipo2() ) tempo=tipo1();
		else tempo=tipo2();
	}
	
	cout << tempo/2ll << "\n";
	for(int i=0;i<N;i++) cout << risultato[i] ;
	cout << "\n";
	
}