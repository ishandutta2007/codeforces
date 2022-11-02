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
#define MAX 
#define INF 0x3f3f3f3f

int n;
vector<int> a , b , c;

int32_t main(){
	cin >> n;
	REP(i , 0 , n){
		int tmp;
		cin >> tmp;
		if(tmp == 1) a.pb(i + 1);
		if(tmp == 2) b.pb(i + 1);
		if(tmp == 3) c.pb(i + 1);
	}
	int q = min(a.size() , min(b.size() , c.size()));
	cout << q << endl;
	REP(i , 0 , q){
		cout << a[i] << " " << b[i] << " " << c[i] << endl;
	}
    return 0;
}