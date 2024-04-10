/*input
7 1000000000
4727447
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int F(int now){ return (now == 4 || now == 7); }
int n , m;
string s;
int32_t main(){
	IOS;
	cin >> n >> m >> s;
	priority_queue<int , vector<int> , greater<int> > pq;
	REP(i , 1 , s.size() + 1) if(s[i - 1] == '4' && s[i] == '7')pq.push(i);
	while(m && pq.size()){
		int now = pq.top(); pq.pop();
		if(s[now - 1] == '4' && s[now] == '7'){
			if(now + 1 != s.size() && now % 2 == 1 && s[now + 1] == '7' && m >= 3) m = m % 2 + 2;
			m --;
			if(now % 2 == 1){
				if(now + 1 != s.size() && s[now + 1] == '7') pq.push(now + 1);
				s[now] = '4';
			}
			if(now % 2 == 0){
				if(now - 1 != 0 && s[now - 2] == '4') pq.push(now - 1);
				s[now - 1] = '7';
			}
		}
	}
	cout << s << endl;
    return 0;
}