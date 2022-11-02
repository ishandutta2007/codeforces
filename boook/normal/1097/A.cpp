/*input
4D
AS AC AD AH 5H
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100
#define INF 0x3f3f3f3f

string a , s[MAX];

int32_t main(){
	IOS;
	cin >> a;
	REP(i , 0 , 5) cin >> s[i];
	REP(i , 0 , 5){
		if(s[i][0] == a[0] || s[i][1] == a[1]){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}