#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
string p , s;
int F(char q , char w){
	int tmp = max(q , w) - min(q , w);
	tmp = min(tmp , min(q , w) + 26 - max(q , w));
	return tmp;
}
int32_t main(){
	cin >> n >> m >> p;
	if(m * 2 > n) reverse(ALL(p)) , m = n + 1 - m;
	s = " " , s += p;
	int lv = 0 , lpo = INF;
	int rv = 0 , rpo = -1;
	int ans = 0;
	REPNM(i , 1 , s.size()){
		if(i * 2 > n) break;
		if(s[i] != s[n + 1 - i]){
			if(i <= m){
				lpo = min(lpo , i);
				lv += F(s[i] , s[n + 1 - i]);
			}
			else {
				rpo = max(rpo , i);
				rv += F(s[i] , s[n + 1 - i]);
			}
		}
	}
	// cout << s << endl;
	// DB4(lv , rv , lpo , rpo);
	ans = lv + rv;
	if(lpo == INF && rpo == -1);
	else if(lpo == INF) ans += rpo - m;
	else if(rpo == -1)  ans += m - lpo;
	else ans += min(m - lpo + (rpo - lpo) , rpo - m + rpo - lpo);
	cout << ans << endl;
    return 0;
}