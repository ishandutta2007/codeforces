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
#define MAX 109000
#define INF 0x3f3f3f3f

string s;
int big[MAX];
int32_t main(){
	IOS;
	cin >> s;
	big[s.size()] = INF;
	RREP(i , s.size() - 1 , 0) big[i] = min(big[i + 1] , s[i] - 'a');
	stack<int> cc;
	int pos = 0;
	while(cc.size() || pos < s.size()){
		if(cc.size() == 0) cc.push(s[pos ++] - 'a');
		else if(pos == s.size()){
			cout << char(cc.top() + 'a');
			cc.pop();
		}
		else {
			if(cc.top() <= big[pos]){
				cout << char(cc.top() + 'a');
				cc.pop();
			}
			else {
				cc.push(s[pos ++] - 'a');
			}
		}
	}
	cout << endl;
    return 0;
}