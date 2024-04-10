/*input
bedefead
5
2 e
1 dc
5 b
7 ef
6 ef
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
#define MAX 100900
#define INF 0x3f3f3f3f


int x[MAX] , ans[MAX] , w[MAX] , cnt[10] , wcnt[70] , t[MAX];
inline int check(){
	REP(i , 0 , 64) t[i] = wcnt[i];
	REP(i , 0 , 6){
		RREP(j , 63 , 0){
			if(j & (1 << i)) t[j] += t[j ^ (1 << i)];
		}
	}
	REP(i , 0 , 64){
		int all = 0;
		REP(j , 0 , 6) all += (i & (1 << j)) ? cnt[j] : 0;
		if(t[i] > all) return 0;
	}
	return 1;
}
string s;
int32_t main(){
	IOS;
	cin >> s;
	int n = s.size() , m;
	REP(i , 1 , n + 1) x[i] = s[i - 1] - 'a';
	REP(i , 1 , n + 1) cnt[x[i]] ++ , w[i] = -1;
	cin >> m;
	REP(i , 1 , m + 1){
		int idx , val = 0;
		cin >> idx >> s;
		REP(j , 0 , s.size()) val |= (1 << (s[j] - 'a'));
		w[idx] = val;
	}
	REP(i , 1 , n + 1) if(w[i] == -1) w[i] = 63;
	REP(i , 1 , n + 1) wcnt[w[i]] ++;

	REP(i , 1 , n + 1){
		int ok = 0;
		REP(j , 0 , 6) if((w[i] & (1 << j)) && cnt[j]){
			cnt[j] --;
			wcnt[w[i]] --;
			if(check()){
				ans[i] = j , ok = 1;
				break;
			}
			else {
				cnt[j] ++;
				wcnt[w[i]] ++;
			}
		}
		if(ok == 0){
	// REP(i , 1 , n + 1) cout << (char('a' + ans[i]));
			return cout << "Impossible" << endl , 0;
		}
	}
	REP(i , 1 , n + 1) cout << (char('a' + ans[i]));
	cout << endl;
    return 0;
}