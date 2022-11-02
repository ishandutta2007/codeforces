/*input
47
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
#define MAX 
#define INF 0x3f3f3f3f

string s , p , ans , now;
int DFS(int id , int can , int gap){
	// DB4(id , can , gap , now);
	if(abs(gap) + id > s.size()) return 0;
	if(id == s.size()) return ans = min(ans , now) , 1;
	else {
		if(can){
			now[id] = '4';
			if(DFS(id + 1 , can , gap + 1)) return 1;
			now[id] = '7';
			if(DFS(id + 1 , can , gap - 1)) return 1;
			return 0;
		}
		else {
			if('4' >= s[id]){
				now[id] = '4';
				if(DFS(id + 1 , s[id] < '4' , gap + 1)) return 1;
			}
			if('7' >= s[id]){
				now[id] = '7';
				if(DFS(id + 1 , s[id] < '7' , gap - 1)) return 1;
			}
			return 0;
		}
	}
}
int32_t main(){
	IOS;
	cin >> s , p = s + ".";
	while(p.size() % 2 != 0) p += '7';
	REP(i , 0 , p.size()){
		if(i + i >= p.size()) p[i] = '7';
		else p[i] = '4';
	}
	REP(i , 0 , s.size()) ans += '9';
	now = ans;
	if(s.size() % 2 == 0) DFS(0 , 0 , 0);
	if(ans[0] == '9') cout << p << endl;
	else cout << ans << endl;
    return 0;
}