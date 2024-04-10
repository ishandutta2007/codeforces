#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define LL  long long int
#define PII pair<int , int>
#define PLL pair< LL , LL >
#define VI  vector<int> 
#define VLL vector<LL> 
#define VPII vector<PII>
#define VPLL vector<PLL>
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
#define MAX 2000000
#define INF 0x3f3f3f3f

int n , m , x[MAX] , z[MAX] , g[MAX] , len;
string s;
void getz(){
    z[0] = s.size();
    int l = 1 , r = 0;
    REPNM(i , 1 , s.size()){
        if(i >= r || z[i - l] >= r - i){
            int tmp = max(i , r);
            while(tmp < s.size() && s[tmp] == s[tmp - i]) tmp ++;
            z[i] = tmp - i;
            if(i < tmp) l = i , r = tmp;
        }
        else z[i] = z[i - l];
    }
    // REP(i , s.size()) cout << z[i] << " " ; cout << endl;
}
int32_t main(){
    cin >> n >> m;
    cin >> s;
    REP(i , m) cin >> x[i] , x[i] --;
    getz() , len = s.size();
    REP(i , m) g[x[i]] ++ , g[x[i] + len] --;
    int ok = 1 , ans = 1;
    REPNM(i , 1 , m){
        if(x[i - 1] + len - 1 < x[i]) continue;
        else if(z[x[i] - x[i - 1]] != len - (x[i] - x[i - 1])) ok = 0;
        // DBGG(z[x[i] - x[i - 1]] , len - (x[i] - x[i - 1]));
    }
    int now = 0 , sum = 0;
    REP(i , n){
        now += g[i];
        if(now == 0) sum ++;
    }
    REP(i , sum) ans = ans * 26LL % 1000000007LL;
    cout << ok * ans << endl;
    return 0;
}