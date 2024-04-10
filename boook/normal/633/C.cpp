/*input

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , x[MAX][26] , v[MAX] , pos = 2 , dp[MAX] , fm[MAX];
string s , p[MAX];
void update(int now , int id , int val){
	if(id == p[val].size()) v[now] = val;
	else {
		int to = (p[val][id] | 32) - 'a';
		if(x[now][to] == 0) x[now][to] = pos ++;
		update(x[now][to] , id + 1 , val);
	}
}
void Print(int now){
	if(now == 0) return ;
	Print(dp[now]);
	cout << p[fm[now]] << " ";
}
int32_t main(){
	IOS;
	cin >> n >> s , s = " " + s;
	cin >> m;
	REP(i , 1 , m + 1) cin >> p[i] , update(1 , 0 , i);
	REP(i , 1 , s.size()) dp[i] = -1;
	REP(i , 1 , s.size()){
		int now = 1;
		RREP(j , i , 1){
			now = x[now][s[j] - 'a'];
			if(now == 0) break;
			if(v[now] && dp[j - 1] >= 0){
				fm[i] = v[now];
				dp[i] = j - 1;
				break;
			}
		}
	}
	Print(s.size() - 1) , cout << endl;
    return 0;
}