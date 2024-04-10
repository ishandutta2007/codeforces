#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
typedef pair< LL , LL > PLL;
typedef vector< int > VI;
typedef vector< LL > VLL;
typedef vector< PII > VPII;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
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

LL n , q;
int main(){
	cin >> n >> q;
	LL root = (n + 1) / 2;
	REP(i , q){
		LL w;
		string s;
		cin >> w >> s;
		LL now = root , fl = root / 2 , lim = root / 2;
		stack<LL> cc;
		while(now != w){
			cc.push(now);
			if(w > now) now += fl , fl /= 2;
			else now -= fl , fl /= 2;
		}
		REP(j , s.size()){
			if(s[j] == 'L'){
				if(fl == 0) continue;
				else cc.push(now) , now -= fl , fl /= 2;
			}
			else if(s[j] == 'R'){
				if(fl == 0) continue;
				else cc.push(now) , now += fl , fl /= 2;
			}
			else if(s[j] == 'U'){
				if(cc.empty()) continue;
				else {
					if(fl == 0) fl = 1;
					else fl *= 2;
					now = cc.top() , cc.pop();
				}
			}
		}
		cout << now << endl;
	}
    return 0;
}