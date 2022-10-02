#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAXN 100010
#define LOG 20 //o 21
#define INF (1<<30)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int A[MAXN];
int next[MAXN][LOG];
int N;

bool res[1<<LOG];

int main(){;
	cin >> N;
	for(int i=0;i<N;i++)cin >> A[i];
	for(int j=0;j<LOG;j++){
		int u=-1;
		for(int i=N-1;i>=0;i--){
			if((1<<j)&A[i])u=i;
			next[i][j]=u;
		}
	}
	//~ for(int i=0;i<N;i++)cout << i << " " << next[i][0] << "\n";
	for(int i=0;i<N;i++){
		int cambi[LOG];
		for(int j=0;j<LOG;j++)cambi[j]=next[i][j];
		sort(cambi,cambi+LOG);
		int act=A[i];
		res[act]=true;
		for(int j=0;j<LOG;j++){
			if(cambi[j]==-1)continue;
			act|=A[cambi[j]];
			res[act]=true;
		}
	}
	int tot=0;
	for(int i=0;i<(1<<LOG);i++)if(res[i])tot++;
	cout << tot;
}