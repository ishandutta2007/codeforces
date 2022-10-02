#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 100100
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int n,m,k;
pair <int, bool> P[2*MAXN];

int main(){
	cin >> n >> m >> k;
	int p;
	for(int i=0;i<n;i++){
		cin >> p;
		P[i]=make_pair(p,0);
	}
	for(int i=n;i<n+m;i++){
		cin >> p;
		P[i]=make_pair(p,1);
	}
	sort(P,P+n+m);
	int diff=0;
	for(int i=n+m-1;i>=0;i--){
		int it=P[i].first;
		while(i>=0 and P[i].first==it){
			if(P[i].second)diff--;
			else diff++;
			i--;
		}
		i++;
		if(diff>0){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	
}