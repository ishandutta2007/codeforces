/*input
34217
34216
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
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string a , b;
int cnt[20];
int DFS(int floor , string s , int ok){
	if(floor == b.size()){
		cout << s << endl;
		exit(0);
	}
	if(ok){
		RREP(i , 9 , 0){
			if(cnt[i]){
				cnt[i] --;
				s += i + '0';
				DFS(floor + 1 , s , ok);
				s.pop_back();
				cnt[i] ++;
			}
		}
	}
	else {
		int val = b[floor] - '0';
		if(cnt[val]){
			cnt[val] --;
			s += '0' + val;
			DFS(floor + 1 , s , ok);
			s.pop_back();
			cnt[val] ++;
		}
			RREP(i , val - 1 , 0){
				if(cnt[i]){
					cnt[i] --;
					s += '0' + i;
					DFS(floor + 1 , s , 1);
					s.pop_back();
					cnt[i] ++;
				}
			}
	}
}
int32_t main(){
	cin >> a >> b;
	if(a.size() < b.size()){
		sort(ALL(a));
		RREP(i , a.size() - 1 , 0) cout << a[i];
		cout << endl;
		return 0;
	}
	if(a.size() > b.size()) while(1);

	REP(i , 0 , a.size()) cnt[a[i] - '0'] ++;
	DFS(0 , "" , 0);
    return 0;
}