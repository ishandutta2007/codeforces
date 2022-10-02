#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#define MAXN 300010
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N,M;
vector <int> aa[MAXN];
bool res[MAXN];

string check(){
	for(int v=1;v<=N;v++){
		int tt=0;
		for(int i=0;i<int(aa[v].size());i++){
			int a=aa[v][i];
			if(res[a]==res[v])tt++;
		}
		if(tt>1)return "SBAGLIATO";
	}
	
	return "FUNGE";
}

int main(){
	cin >> N >> M;
	int A,B;
	for(int i=0;i<M;i++){
		cin >> A >> B;
		aa[A].push_back(B);
		aa[B].push_back(A);
	}
	for(int i=1;i<=N/2;i++)res[i]=1;
	stack <int> coda;
	for(int i=1;i<=N;i++)coda.push(i);
	while(!coda.empty()){
		int v=coda.top();
		coda.pop();
		int tt=0;
		for(int i=0;i<int(aa[v].size());i++){
			int a=aa[v][i];
			if(res[a]==res[v])tt++;
		}
		if(tt<=1)continue;
		res[v]=!res[v];
		for(int i=0;i<int(aa[v].size());i++){
			int a=aa[v][i];
			if(res[a]==res[v])coda.push(a);
		}
	}
	for(int i=1;i<=N;i++)cout << res[i];
	cout << "\n";
	//~ cout << check() << "\n";
}