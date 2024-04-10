/*input
YISVOWEL
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)     for(int i = j ; i < k ; ++i)
#define RREP(i , j , k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl  
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 600000
#define INF 0x3f3f3f3f

string s;
int bit1[MAX] , bit2[MAX];
void update1(int from , int val){ for(int i = from ; i < MAX ; i += i & -i) bit1[i] += val; }
void update2(int from , int val){ for(int i = from ; i < MAX ; i += i & -i) bit2[i] += val; }
int query1(int from){
	int res = 0;
	for(int i = from ; i > 0 ; i -= i & -i) res += bit1[i];
	return res;
}
int query2(int from){
	int res = 0;
	for(int i = from ; i > 0 ; i -= i & -i) res += bit2[i];
	return res;
}
int query1(int l , int r){ return query1(r) - query1(l - 1); }
int query2(int l , int r){ return query2(r) - query2(l - 1); }
int32_t main(){
	cin >> s;
	REP(i , 0 , s.size()){
		int ok = 0;
		if(s[i] == 'I')	ok = 1;
		if(s[i] == 'E')	ok = 1;
		if(s[i] == 'A')	ok = 1;
		if(s[i] == 'O')	ok = 1;
		if(s[i] == 'U')	ok = 1;
		if(s[i] == 'Y')	ok = 1;
		if(ok){
			update1(i + 1 , 1);
			update2(i + 1 , min(i + 1 , (int)(s.size()) - i));
		}
	}
	double ans = 0;
	REP(i , 1 , s.size() + 1){
		int tmp = min(i , (int)(s.size()) + 1 - i);
		int l = tmp , r = (int)(s.size()) + 1 - tmp;
		double v = query1(l + 1 , r - 1) * tmp + query2(1 , l) + query2(r , s.size());
		// DB4(i , l , r , query1(l + 1 , r - 1) * tmp + query2(1 , l) + query2(r , s.size()));
		ans += v / i;
	}
	printf("%.11f\n", ans);
    return 0;
}