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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m , k;
int x[MAX][2];
int check(int a , int b){
	if(a > b) swap(a , b);
	if(m >= a && k >= b) return 1;
	else return 0;
}
int F(int a , int b , int c , int d){
	int cnt = 0 , q = 0 , w = 0;
	q = max(a , c) , w = b + d;
	if(check(q , w)) cnt = max(cnt , a * b + c * d);
	q = a + c , w = max(b , d);
	if(check(q , w)) cnt = max(cnt , a * b + c * d);
	return cnt;
}
int32_t main(){
	cin >> n >> m >> k;
	if(m > k) swap(m , k);
	REP(i , 0 , n) cin >> x[i][0] >> x[i][1];
	int ans = 0;
	REP(i , 0 , n){
		REP(j , i + 1 , n){
			int a = x[i][0] , b = x[i][1];
			int c = x[j][0] , d = x[j][1];
			ans = max(ans , F(a , b , c , d));
			ans = max(ans , F(a , b , d , c));
		}
	}
	cout << ans << endl;
    return 0;
}