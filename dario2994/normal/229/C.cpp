#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef unsigned long long ULL;
#define INF 1<<23
#define MAXN 1000010

ULL N,M;
ULL deg[MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for(ULL i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}
	ULL res=0;
	for(ULL i=1;i<=N;i++)res+=deg[i]*(N-1-deg[i]);
	ULL ris=N*(N-1)*(N-2)/6;
	cout << ris-(res/2);
}