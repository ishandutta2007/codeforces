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
#define MAX 100009
#define INF 0x3f3f3f3f

int n , a , b , x[MAX] , len;
set<int> cc;
int32_t main(){
    cin >> n >> len >> a >> b;
    REP(i , n) cin >> x[i] , cc.insert(x[i]);
    int cnt = 0 , tmp = 0;
    int q , w , e;
    int qqq = 0 , qqe;
    int www = 0 , wwe;
    REP(i , n) if(cc.find(x[i] + a) != cc.end()) cnt |= 1 , q = i;
    REP(i , n) if(cc.find(x[i] + b) != cc.end()) cnt |= 2 , w = i;
    REP(i , n) if(cc.find(x[i] + a + b) != cc.end()) tmp = 1 , e = i;
    REP(i , n) if(x[i] + b <= len && cc.find(x[i] + b - a) != cc.end()) qqq = 1 , qqe = i;
    REP(i , n) if(x[i] - a >= 0 && cc.find(x[i] - a + b) != cc.end()) www = 1 , wwe = i;
    if(cnt == 3) cout << "0\n" ;
    else if(cnt == 1){
        cout << 1 << "\n";
        cout << b << endl;
    }
    else if(cnt == 2){
        cout << 1 << "\n";
        cout << a << endl;
    }
    else if(tmp == 1){
        cout << 1 << "\n";
        cout << x[e] + a << "\n";
    }
    else if(qqq == 1){
        cout << 1 << "\n";
        cout << x[qqe] + b << "\n";
    }
    else if(www == 1){
        cout << 1 << "\n";
        cout << x[wwe] - a << "\n";
    }
    else {
        cout << 2 << "\n";
        cout << a << " " << b << "\n";
    }
    return 0;
}