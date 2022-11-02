/*input
6
ababaa
010101
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
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

string s , ss;
int sa[MAX] , rk[MAX] , lcp[MAX];
int tma[2][MAX] , c[MAX];
void getsa(){
	int *x = tma[0] , *y = tma[1] , m = 200 , n = s.size();
	REP(i , 0 , m) c[i] = 0;
	REP(i , 0 , n) c[x[i] = s[i]] ++;
	REP(i , 1 , m) c[i] += c[i - 1];
	RREP(i , n - 1 , 0) sa[--c[x[i]]] = i;

	for(int k = 1 ; k <= n ; k <<= 1){
		REP(i , 0 , m) c[i] = 0;
		REP(i , 0 , n) c[x[i]] ++;
		REP(i , 1 , m) c[i] += c[i - 1];
		int p = 0;
		REP(i , n - k , n) y[p ++] = i;
		REP(i , 0 , n) if(sa[i] >= k) y[p ++] = sa[i] - k;
		RREP(i , n - 1 , 0) sa[--c[x[y[i]]]] = y[i];

		y[sa[0]] = p = 0;
		REP(i , 1 , n){
			int a = sa[i - 1] , b = sa[i];
			if(x[a] == x[b] && a + k < n && b + k < n && x[a + k] == x[b + k]);
			else p ++;
			y[sa[i]] = p;
		}

		if(n == p + 1) break;
		swap(x , y);
		m = p + 1;
	}
}
int getlcp(){
	int n = s.size() , tmp = 0;
	REP(i , 0 , n) rk[sa[i]] = i;
	REP(i , 0 , n){
		if(rk[i] == 0) lcp[0] = 0;
		else {
			if(tmp) tmp --;
			int po = sa[rk[i] - 1];
			while(tmp + i < n && tmp + po < n && s[tmp + i] == s[tmp + po]) tmp ++;
			lcp[rk[i]] = tmp;
		}
	}
}
int ok[MAX] , l[MAX] , r[MAX];
int L(int id , int val){ return lcp[id] < val ? id : L(l[id] , val); }
int R(int id , int val){ return lcp[id] < val ? id : R(r[id] , val); }
int32_t main(){
	IOS , cin >> s >> s >> ss;

	reverse(ALL(s)) , reverse(ALL(ss));
	getsa() , getlcp();
	int ans = 0 , n = s.size();

	REP(i , 0 , n) if(ss[i] == '0') ans = max(ans , n - i);
	REP(i , 0 , n) ok[i] = (ss[sa[i]] == '0');

	// cout << s << endl;
	// cout << ss << endl;
	// REP(i , 0 , n) cout << sa[i] << " " ; cout << endl;
	// REP(i , 0 , n) cout << rk[i] << " " ; cout << endl;
	// REP(i , 0 , n) cout << lcp[i] << " " ; cout << endl;
	// REP(i , 0 , n) cout << ok[i] << " "; cout << endl;


	REP(i , 1 , n) ok[i] += ok[i - 1];

	lcp[0] = lcp[n] = -1;
	REP(i , 1 , n)      l[i] = L(i - 1 , lcp[i]);
	RREP(i , n - 1 , 1) r[i] = R(i + 1 , lcp[i]);
	REP(i , 1 , n){
		int ll = l[i] , rr = r[i] - 1;
		int sum = (ll == 0) ? ok[rr] : ok[rr] - ok[ll - 1];
		// DB4(ll , rr , sum , lcp[i]);
		ans = max(ans , lcp[i] * sum);
	}
	cout << ans << endl;
    return 0;
}