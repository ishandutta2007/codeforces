#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define MAXID 1000010
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n,m;
priority_queue <pair <int,int> > posti;//promessa,-quello prima!
int pos[MAXID];
int next[MAXID];
int previous[MAXID];

int val(int x){
	if(previous[next[x]]!=x)return -1;
	if(x==0)return next[x]-1;
	else if(next[x]==n+1)return n-x;
	else return (next[x]-x)/2;
}

bool f(pair <int,int> U){
	if(val(-U.second)==U.first)return true;
	return false;
}

void clean(){
	while(!f(posti.top()))posti.pop();
}

void create(int x){
	if(next[x]<=x+1)return;
	posti.push(make_pair(val(x),-x));
}

int main(){
	cin >> n >> m;
	next[0]=n+1;
	previous[n+1]=0;
	posti.push(make_pair(n,0));
	vector <int> res;
	for(int i=0;i<m;i++){
		int t,id;
		cin >> t >> id;
		if(t==1){
			clean();
			pair <int,int> act=posti.top();
			int ii=-act.second;
			int ff=next[ii];
			posti.pop();
			int mm;
			if(ii==0)mm=1;
			else if(ff==n+1)mm=n;
			else mm=(ii+ff)/2;
			res.push_back(mm);
			//~ cout << ii << " " << ff << " " << mm << endl;
			cout.flush();
			pos[id]=mm;
			previous[mm]=ii;
			next[mm]=ff;
			next[ii]=mm;
			previous[ff]=mm;
			create(ii);
			create(mm);
		}
		if(t==2){
			int mm=pos[id];
			int ii=previous[mm];
			int ff=next[mm];
			next[ii]=ff;
			previous[ff]=ii;
			create(ii);
		}
	}
	for(int i=0;i<int(res.size());i++)cout << res[i] << "\n";
}