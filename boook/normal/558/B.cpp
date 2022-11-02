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
#define MAX 200000
#define INF 0x3f3f3f3f

map<int , int> cnt , l , r;
int n , x[MAX];
int32_t main(){
    cin >> n;
    REP(i , n) cin >> x[i];
    REP(i , n){
        cnt[x[i]] ++;
        if(l.find(x[i]) == l.end()) l[x[i]] = i;
        else l[x[i]] = min(l[x[i]] , i);
        if(r.find(x[i]) == r.end()) r[x[i]] = i;
        else r[x[i]] = max(r[x[i]] , i);
    }
    int ans = 0 , ql = 0 , qr = INF;
    for(auto i : cnt) ans = max(ans , i.B);
    REP(i , n){
        if(cnt[x[i]] == ans){
            if(r[x[i]] - l[x[i]] < qr - ql) qr = r[x[i]] , ql = l[x[i]];
        }
    }
    cout << ql + 1 << " " << qr + 1 << endl;
    return 0;
}