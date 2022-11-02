#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> PII;
typedef long long int LL;
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
///---------------------------
#define MAX 20
#define INF 0x3f3f3f3f
#define debug 1

int main(){
	vector<LL> v;
	LL n , k;
	while(cin >> n >> k){
		v.clear(); k--;
		LL q = sqrt(n);
		REPNM(i , 1 , q + 1){
			if(n % i == 0 && n / i != i) v.pb(i) , v.pb(n/i);
		}
		if(n % q == 0 && n / q == q)v.pb(q);
		sort(ALL(v));

		// REP(i , v.size()) cout << v[i] << " "; cout << endl;

		if(k >= v.size()) cout << -1 << endl;
		else cout << v[k] << endl;
	}
	
	
    return 0;
}