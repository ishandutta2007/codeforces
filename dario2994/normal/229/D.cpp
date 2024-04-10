#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef unsigned long long ULL;
#define INF 1<<23
#define MAXN 5005

int N;
int S[MAXN];
int din[MAXN][MAXN];

int next(int i,int k){
	int * it=lower_bound(S,S+N+1,S[k]+(S[k]-S[i]));
	if(it<S+N+1)return it-S;
	return -1;
}

int main(){
	cin >> N;
	for(int i=1;i<=N;i++)cin >> S[i];
	for(int i=1;i<=N;i++)S[i]+=S[i-1];
	for(int i=N-1;i>=0;i--)for(int k=N;k>i;k--){
		din[i][k]=INF;
		if(k==N){
			din[i][k]=N-i-1;
			continue;
		}
		if(k<N)din[i][k]=din[i][k+1];
		int it=next(i,k);
		if(it!=-1)din[i][k]=min(din[i][k],k-i-1+din[k][it]);
	}
	cout << din[0][1];
}