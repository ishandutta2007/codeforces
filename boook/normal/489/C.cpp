#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f
#define debug 1

void Pre(){}

void Init(){}

void Read(){}

void Solve(){}

int main(){
	int n , m;
	RII(n , m);
	if(m == 0){
		if(n == 1) puts("0 0");
		else puts("-1 -1");
	}
	else {
		priority_queue<int> big;
		priority_queue<int , vector<int> , greater<int> > sml , thr;
		int tmp = m;
		while(tmp){
			if(tmp >= 9) big.push(9) , sml.push(9) , thr.push(9) , tmp -= 9;
			else big.push(tmp) , sml.push(tmp) , thr.push(tmp) , tmp -= tmp;
		}

		if(big.size() > n) puts("-1 -1");
		else {
			string q , w , zero , rr , sss , ssszero , sssrr;
			REP(i , n){
				if(big.size()) w += big.top() + '0' , big.pop();
				else w += "0";
			}
			q += sml.top() + '0' , sml.pop();
			REP(i , n - 1){
				if(sml.size()) rr += sml.top() + '0' , sml.pop();
				else zero += "0";
			}

			sss += "1";
			int qqq = thr.top(); thr.pop(); 
			if(qqq != 1) thr.push(qqq - 1);

			REP(i , n - 1){
				if(thr.size()) sssrr += thr.top() + '0' , thr.pop();
				else ssszero += "0";
			}

			q += zero + rr;
			sss += ssszero + sssrr;
			if(thr.size());
			else q = sss;
			cout << q << " " << w << endl;
			
		}

	}
	
    return 0;
}