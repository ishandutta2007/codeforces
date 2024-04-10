#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string s;
int32_t main(){
    IOS;
    cin >> s >> s;
    int v1 = 0 , v2 = 0;
    REP(i , 0 , s.size()){
    	v1 += s[i] == '0';
    	v2 += s[i] == '1';
    }
    v2 = min(v2 , 1);
	REP(i , 0 , v2) cout << 1 ;
	REP(i , 0 , v1) cout << 0 ;
	cout << endl;
    return 0;
}