#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define INF 2000000000
#define MAXN 500000
#define MAXM 1000000
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int main(){
	int n,m,h;
	cin >> n >> m >> h;
	int S=0;
	int sh;
	for(int i=1;i<=m;i++){
		int u;
		cin >> u;
		S+=u;
		if(i==h)sh=u;
	}
	if(S<n){
		cout << -1;
		return 0;
	}
	long double a=S-n;
	long double b=S-1;
	//cout << a << " " << b << " " << sh << endl;
	long double ris=1;
	for(long double i=0;i<sh-1;i++)ris=ris*(a-i)/(b-i);
	cout.precision(13);
	cout << 1-ris;
}