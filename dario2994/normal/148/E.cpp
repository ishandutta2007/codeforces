#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 102
#define MAXM 10003
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N,M;
int A[MAXN][MAXN];
int l[MAXN];
int B[MAXN][MAXN];
int din[MAXN][MAXM];

void build(int x){
	// fino a i NON compreso, da j compreso!
	int prefix[l[x]+1];
	int suffix[l[x]+1];
	prefix[0]=0;
	for(int i=1;i<=l[x];i++)prefix[i]=prefix[i-1]+A[x][i-1];
	suffix[l[x]]=0;
	for(int i=l[x]-1;i>=0;i--)suffix[i]=suffix[i+1]+A[x][i];
	//~ cout << endl;
	//~ for(int i=0;i<=l[x];i++)cout << suffix[i] << " ";
	//~ cout << endl;
	int dp[l[x]+1];
	for(int i=0;i<=l[x];i++)dp[i]=0;
	for(int i=0;i<=l[x];i++)for(int j=i;j<=l[x];j++) if(prefix[i]+suffix[j]>dp[i+l[x]-j])dp[i+l[x]-j]=prefix[i]+suffix[j];
	for(int i=0;i<=l[x];i++)B[x][i]=dp[i];
}

int main(){
	//~ ifstream in("input.txt");
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> l[i];
		for(int j=0;j<l[i];j++)cin >> A[i][j];
	}
	for(int i=0;i<N;i++)build(i);
	//~ for(int i=0;i<N;i++){
		//~ cout << i << ": ";
		//~ for(int j=0;j<=l[i];j++)cout << B[i][j] << " ";
		//~ cout << endl;
	//~ }
	for(int i=0;i<=min(M,l[0]);i++)din[0][i]=B[0][i];
	for(int i=1;i<N;i++){
		for(int j=0;j<=M;j++){
			for(int k=0;k<=min(j,l[i]);k++){
				int t=B[i][k]+din[i-1][j-k];
				if(din[i][j]<t)din[i][j]=t;
			}
		}
	}
	cout << din[N-1][M];
}