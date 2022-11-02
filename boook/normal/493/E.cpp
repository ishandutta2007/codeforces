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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int t , a , b;
int32_t main(){
	cin >> t >> a >> b;
	if(t == 1 && a == 1 && b == 1) puts("inf");
	else if(t == a && t == b) puts("2");
	else if(a == b) puts("1");
	else if(t > a || a > b) puts("0");
	else if(a == 1) puts("0");
	else {
		int tmb = b , ok = 1;
		while(tmb > 1 && ok && a != 1){
			if(tmb % a != 0) ok = 0;
			else tmb /= a;
		}
		if(tmb == 1 && ok && t == 1) puts("1");
		else {
			VI v;
			while(b > 0) v.pb(b % a) , b /= a;
			int tmp = 0;
			RREP(i , v.size() - 1 , 0) tmp = tmp * t + v[i];
			if(tmp == a) puts("1");
			else puts("0");
		}
	}
    return 0;
}