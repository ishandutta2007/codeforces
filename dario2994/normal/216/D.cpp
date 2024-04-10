#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#define INF 1000000000
#define MAXN 1005
#define MAXC 100005
typedef long long int LL; 
typedef unsigned long long int ULL; 
using namespace std;

LL N;
vector <LL> bridge[MAXN];
int l[MAXN];

void leggi(){
	cin >> N;
	for (int i=0; i<N; i++) {
		LL k;
		cin >> k;
		for (int j=0; j<k; j++) {
			LL a;
			cin >> a;
			bridge[i].push_back(a);
		}
		sort(bridge[i].begin(),bridge[i].end());
		l[i]=bridge[i].size();
	}
}

int main(){
	leggi();
	int res=0;
	for(int i=0;i<N;i++){
		int mali=0;
		int quanti[l[i]];
		for(int j=0;j<l[i];j++)quanti[j]=0;
		int a=-1;
		int p=i-1;
		if(p==-1)p=N-1;
		while(a+1<l[p] and bridge[p][a+1]<bridge[i][0])a++;
		for(int j=0;j<l[i]-1;j++){
			int act=bridge[i][j];
			int succ=bridge[i][j+1];
			while(a+1<l[p] and act<bridge[p][a+1] and bridge[p][a+1]<succ){
				quanti[j]++;
				a++;
			}
		}
		int tanti[l[i]];
		for(int j=0;j<l[i];j++)tanti[j]=0;
		a=-1;
		p=i+1;
		if(p==N)p=0;
		while(a+1<l[p] and bridge[p][a+1]<bridge[i][0])a++;
		for(int j=0;j<l[i]-1;j++){
			int act=bridge[i][j];
			int succ=bridge[i][j+1];
			while(a+1<l[p] and act<bridge[p][a+1] and bridge[p][a+1]<succ){
				tanti[j]++;
				a++;
			}
		}
		for (int j=0; j<l[i]-1; j++){
			//~ if (i==6) {
				//~ cout << j <<": "<< quanti[j] << " " <<tanti[j] << endl;
			//~ }
			 if (quanti[j]!=tanti[j]) {
				 res++;
			 }
		}
	}
	cout << res;
}