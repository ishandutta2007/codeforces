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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , x[MAX] , fr[MAX] , ba[MAX] , bit[MAX];
int ans;
map<int , int> cc , dd;
void update(int from , int val){
    for(int i = from ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int cnt = 0;
    for(int i = from ; i > 0 ; i -= i & -i)
        cnt += bit[i];
    return cnt;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , n) cin >> x[i];
    RREP(i , n - 1 , 0){
        if(cc.find(x[i]) == cc.end()) cc[x[i]] = ba[i] = 1;
        else ba[i] = ++cc[x[i]];
        update(ba[i] , 1);
    }
    REP(i , n){
        update(ba[i] , -1);
        if(dd.find(x[i]) == dd.end()) dd[x[i]] = fr[i] = 1;
        else fr[i] = ++dd[x[i]];
        ans += query(fr[i] - 1);
    }
    cout << ans << "\n";
    return 0;
}