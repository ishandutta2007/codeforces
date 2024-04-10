#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 200100
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N;
int seq[MAXN];
int f[2*MAXN];
vector <int> T[2*MAXN];
int dest[2*MAXN];
ULL sum[2*MAXN];

inline int mm(int x){
	if(x%N==0)return N;
	return x%N;
}

void dfs(int v, int root, ULL ss){
	dest[v]=root;
	sum[v]=ss;
	for(int i=0;i<int(T[v].size());i++){
		int a=T[v][i];
		dfs(a,root,ss+(ULL)seq[mm(a)]);
	}
}

int main(){
	//~ ifstream cin("input.txt");
	cin >> N;
	for(int i=2;i<=N;i++){
		int a;
		cin >> a;
		seq[i]=a;
		if(0<i+a and i+a<=N)f[i]=N+i+a;
		if(0<i-a and i-a<=N)f[N+i]=i-a;
	}
	//~ for(int i=1;i<=2*N;i++)cout << i << ": " << f[i] << "\n";
	for(int i=1;i<=2*N;i++)if(f[i]!=0)T[f[i]].push_back(i);
	for(int i=1;i<=2*N;i++){
		if(i%N==1)continue;
		if(f[i]==0)dfs(i,i,seq[mm(i)]);
	}
	for(int i=1;i<=N-1;i++){
		int xxx=dest[N+i+1];
		if(xxx==0 or xxx==1)cout << -1 << "\n";
		else if(xxx==N+1)cout << ((ULL)(2*i))+sum[N+i+1] << "\n";
		else cout << ((ULL)i)+sum[N+i+1] << "\n";
	}
}