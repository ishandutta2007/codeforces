#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 1<<23
#define MAXN 100010

int N,M;
vector <int> amici[MAXN];
vector <int> peso[MAXN];
vector <int> stop[MAXN];

int quando(int v,int t){
	vector <int>::iterator it=lower_bound(stop[v].begin(),stop[v].end(),t);
	while(it<stop[v].end() and (*it)==t){
		t++;
		it++;
	}
	return t;
}

int dijstra(){
	bool fatto[N+1];
	for(int i=1;i<=N;i++)fatto[i]=false;
	priority_queue <pair <int,int> > coda;
	coda.push(make_pair(0,1));
	while(!coda.empty()){
		pair <int,int> act=coda.top();
		coda.pop();
		int v=act.second;
		//~ cout << v << endl;
		int t=-act.first;
		if(fatto[v])continue;
		if(v==N)return t;
		fatto[v]=true;
		int t1=quando(v,t);
		for(int i=0;i<int(amici[v].size());i++){
			int a=amici[v][i];
			if(fatto[a])continue;
			coda.push(make_pair(-(t1+peso[v][i]),a));
		}
	}
	return -1;
}

int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b,p;
		cin >> a >> b >> p;
		amici[a].push_back(b);
		amici[b].push_back(a);
		peso[a].push_back(p);
		peso[b].push_back(p);
	}
	for(int i=1;i<=N;i++){
		int k;
		cin >> k;
		for(int j=0;j<k;j++){
			int t;
			cin >> t;
			stop[i].push_back(t);
		}
	}
	cout << dijstra();
}