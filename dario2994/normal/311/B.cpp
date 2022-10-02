#include <iostream>
#include <fstream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#define MAXN 100010
typedef long long LL;
using namespace std;

int M,N,p;

LL D[MAXN];
LL A[MAXN];
LL preA[MAXN];

void pre(){
	ios_base::sync_with_stdio(0);
	cin >> M >> N >> p;
	LL arr;
	for(int i=2;i<=M;i++){
		cin >> arr;
		D[i]=D[i-1]+arr;
	}
	LL hi,ti;
	for(int i=1;i<=N;i++){
		cin >> hi >> ti;
		A[i]=ti-D[hi];
	}
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++)preA[i]=preA[i-1]+A[i];
}

LL din[MAXN][101];
LL B[MAXN];

int compare(int u,int v){//u<v. Da quando in poi v batte u?
	if(A[u]==A[v]){
		if(B[u]<B[v])return u+1;
		else return 1;
	}
	LL i0=(B[v]-B[u]) / (A[v]-A[u]);
	if(i0<=0)return 1;
	if( (B[v]-B[u]) % (A[v]-A[u]) ) i0++;
	if(i0<=0)return 1;
	return min(LL(u+1),i0);
}

int main(){
	pre();
	//~ if(N==100000)return 0;
	for(int i=N-1;i>=1;i--) din[i][1]=din[i+1][1]+A[N]-A[i];
	for(int o=2;o<=p;o++){
		for(int i=N;i>=1;i--)B[i]=din[i+1][o-1]+(i+1)*A[i]-preA[i];
		
		vector <pair <LL,int> > coda;
		for(int t=1;t<=N;t++){
			while(!coda.empty()){
				int u=coda.back().second;
				LL i=coda.back().first;
				if(B[t]-i*A[t]<=B[u]-i*A[u])coda.pop_back();
				//~ if(compare(u,t)<=coda.back().first)coda.pop_back();
				else break;
			}
			if(coda.empty())coda.push_back(make_pair(1,t));
			else{
				int u=coda.back().second;
				if(compare(u,t)<=N)coda.push_back(make_pair( compare(u,t) ,t));
			}
		}
		
		for(int i=0;i<int(coda.size())-1;i++){
			int t=coda[i].second;
			for(int j=coda[i].first;j<coda[i+1].first;j++)din[j][o]=B[t]-(LL)j*A[t];
		}
		for(int i=1;i<=N;i++)din[i][o]+=preA[i-1];
	}
	
	cout << din[1][p] << "\n";
}