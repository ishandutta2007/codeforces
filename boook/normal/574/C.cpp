#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long 
#define MAX 200000
#define INF 0x3f3f3f3f

int n , x[MAX];

int32_t main(){
	cin >> n;
	REP(i , 0 , n) cin >> x[i];
	REP(i , 0 , n){
		while(x[i] % 2 == 0) x[i] /= 2;
		while(x[i] % 3 == 0) x[i] /= 3;
	}
	int tmp = x[0];
	REP(i , 0 , n){
		if(tmp != x[i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
    return 0;
}