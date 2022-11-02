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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m;
int a[MAX] , b[MAX];

int32_t main(){
    cin >> n >> m;
    REP(i , n) cin >> a[i];
    REP(i , m) cin >> b[i];
    sort(a , a + n);
    sort(b , b + m , greater<int>());
    a[n] = INF , b[n] = -INF;
    PII q = mp(a[0] , 1) , w = mp(b[0] , 1);
    int ans = 0;
    while(q.A < w.A){
        while(q.B < n && q.A == a[q.B]) q.B ++;
        while(w.B < m && w.A == b[w.B]) w.B ++;
        if(q.B <= w.B){
            int tmp = min(w.A , a[q.B]);
            ans += q.B * (tmp - q.A);
            q.A = tmp;
        }
        else {
            int tmp = max(q.A , b[w.B]);
            ans += w.B * (w.A - tmp);
            w.A = tmp;
        }
    }
    cout << ans << "\n";
    return 0;
}