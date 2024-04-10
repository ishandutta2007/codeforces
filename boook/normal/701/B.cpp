#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
//------------------------------------------
#define int long long
#define MAX 100900

int n , m , x[MAX][2];

set<int> a , b;

int32_t main(){
	cin >> n >> m;
	REP(i , 1 , m + 1) cin >> x[i][0] >> x[i][1];
	REP(i , 1 , m + 1){
		a.insert(x[i][0]);
		b.insert(x[i][1]);
		int tma = n - a.size();
		int tmb = n - b.size();
		cout << tma * tmb << " ";
	}
	cout << endl;
	return 0;
}