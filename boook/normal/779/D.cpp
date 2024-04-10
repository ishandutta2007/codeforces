#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout<<i<<" "<<j<<endl;
#define DB4(i,j,k,l)  if(debug) cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
#define RI(i)       scanf("%d",&i)
#define RII(i,j)    scanf("%d%d",&i,&j)
#define RIII(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define RL(i)       scanf("%lld",&i)
#define RLL(i,j)    scanf("%lld%lld",&i,&j)
#define RLLL(i,j,k) scanf("%lld%lld%lld",&i,&j,&k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 200090
#define INF 0x3f3f3f3f
#define debug 1

string a , b;
int x[MAX] , use[MAX];
int F(int now){

	MEM(use , 0);
	REP(i , now) use[x[i] - 1] = 1;

	string s;
	REP(i , a.size()){
		if(!use[i]) s += a[i];
	}

	int po = 0;
	REP(i , b.size()){
		while(po < s.size() && b[i] != s[po]) po ++;
		po ++;
		if(po > s.size()) return 0;
	}
	return 1;
}
int main(){
	IOS;
	while(cin >> a >> b){
		REP(i , a.size()) cin >> x[i];
		int fr = 0 , ba = a.size() + 1;
		while(ba - fr > 1){
			int mid = (ba + fr) / 2;
			if(F(mid)) fr = mid;
			else ba = mid;
		}
		cout << fr << endl;
	}
    return 0;
}