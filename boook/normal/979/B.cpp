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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 10
#define INF 0x3f3f3f3f

int n , v[MAX];
string a;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , 3 + 1){
    	cin >> a;
    	int big = 0;
    	map<char , int> cc;
    	REP(j , 0 , a.size()) cc[a[j]] ++ , big = max(big , cc[a[j]]);
    	v[i] = min(int(a.size()) , n + big);
    	if(big == a.size() && n == 1) v[i] --;
    }
	if(v[1] > v[2] && v[1] > v[3]) return cout << "Kuro" << endl , 0;
	if(v[2] > v[1] && v[2] > v[3]) return cout << "Shiro" << endl , 0;
	if(v[3] > v[1] && v[3] > v[2]) return cout << "Katie" << endl , 0;
	cout << "Draw" << endl;
    return 0;
}