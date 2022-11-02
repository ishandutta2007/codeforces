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
typedef long long LL;
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , m , tmp;
VI a , b;
PII ans;
void F(PII now){
	// DBGG(now.A , now.B);
	int qq = ans.A - ans.B;
	if(now.A - now.B > qq) ans = now;
	if(now.A - now.B < qq) return ;
	if(now.A > ans.A) ans = now;
}
int32_t main(){
	// cout << (1 << 20);
	cin >> n;
	REP(i , n) cin >> tmp , a.pb(tmp);
	cin >> m;
	REP(i , m) cin >> tmp , b.pb(tmp);
	sort(ALL(a));
	sort(ALL(b));
	ans = mp((int)a.size() * 2 , (int)b.size() * 2);
	REP(i , n){
		int now = -1 , goal = a[i];
		RREP(j , 20 , 0){
			int to = now + (1LL << j);
			if(to >= m) continue;
			else if(b[to] < goal) now = to;
		}
		// DBGG("now = " , now);
		if(now == m - 1) F(mp((int)a.size() * 3 - i , (int)b.size() * 2));
		else F(mp((int)a.size() * 3 - i , (int)b.size() * 3 - (now + 1)));
	}
	cout << ans.A << ":" << ans.B << "\n";
    return 0;
}