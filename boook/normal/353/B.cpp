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
#define MAX 300
#define INF 0x3f3f3f3f

int n , x[MAX] , to[MAX] , cnt[MAX];
set<int> a , b , v;
int main(){
    cin >> n;
    REP(i , n + n) cin >> x[i] , cnt[x[i]] ++;

    REP(i , MAX){
    	if(cnt[i] >= 2) v.insert(i) , v.insert(-i) , a.insert(i) , b.insert(i);
    }
    REP(i , n + n){
    	if(v.find(x[i]) != v.end() && to[i] == 0) to[i] = 1 , v.erase(x[i]); 
    	if(v.find(-x[i]) != v.end() && to[i] == 0) to[i] = 2 , v.erase(-x[i]); 
    }

    REP(i , n){
    	int ok = 0;
    	REP(i , n + n) if(a.find(x[i]) == a.end() && to[i] == 0){ to[i] = 1 , a.insert(x[i]) , ok ++; break; }
    	REP(i , n + n) if(b.find(x[i]) == b.end() && to[i] == 0){ to[i] = 2 , b.insert(x[i]) , ok ++; break; }
    	if(ok != 2) break;
    }
    int sum = a.size();
    REP(i , n + n){
    	if(sum < n && to[i] == 0) to[i] = 1 , sum ++;
    	else if(to[i] == 0) to[i] = 2; 
    }
    cout << a.size() * b.size() << endl;
    REP(i , n + n){
    	cout << to[i] << " ";
    }
    cout << endl;
    return 0;
}