#include <iostream>
#include <fstream>
#define MAXN 100010
#define INF (1e9+1)
using namespace std;

int N, res;
int X[MAXN], ll[MAXN], rr[MAXN];

int main(){
	cin >> N;
	for(int i=1;i<=N;i++)cin >> X[i];
	X[0]=X[N+1]=INF;
	for(int i=1;i<=N;i++){
		ll[i]=i-1;
		while(X[ll[i]]<X[i])ll[i]=ll[ll[i]];
		if(1<=ll[i])res=max(res,X[i]^X[ll[i]]);
	}
	for(int i=N;i>=1;i--){
		rr[i]=i+1;
		while(X[rr[i]]<X[i])rr[i]=rr[rr[i]];
		if(rr[i]<=N)res=max(res,X[i]^X[rr[i]]);
	}
	cout << res << "\n";
}