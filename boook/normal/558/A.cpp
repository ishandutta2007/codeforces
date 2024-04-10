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
#define MAX 10000
#define INF 0x3f3f3f3f

int n;
PII a[MAX];
int32_t main(){
    cin >> n;
    REP(i , n) cin >> a[i].A >> a[i].B;
    sort(a , a + n);

    int cnt = 0 , q = 0;
    REP(i , n)
        if(a[i].A > 0) cnt ++;
        else q ++;
    if(cnt > q){
        int tmp = q * 2 + 1 , ans = 0;
        REP(i , tmp) ans += a[i].B;
        cout << ans << endl;
    }
    else if(cnt == q){
        int ans = 0;
        REP(i , n) ans += a[i].B;
        cout << ans << endl;
    }
    else {
        int tmp = cnt * 2 + 1 , ans = 0;
        REP(i , tmp) ans += a[n - 1 - i].B;
        cout << ans << endl;
    }
    return 0;
}