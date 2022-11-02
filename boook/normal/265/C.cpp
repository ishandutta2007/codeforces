/*input
lrlrr
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

string s;
deque<int> dq;
int32_t main(){
	IOS;
	cin >> s;
	int siz = s.size();
	dq.push_back(s.size());
	RREP(i , siz - 2 , 0){
		if(s[i] == 'l') dq.push_back(i + 1);
		if(s[i] == 'r') dq.push_front(i + 1);
	}
	for(auto to : dq) cout << to << endl;
    return 0;
}