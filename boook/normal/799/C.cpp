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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k;
PII a[MAX] , b[MAX];
int ma[MAX] , mb[MAX];
int apo = 0 , bpo = 0;
int F(int lim , int gd){
    int now = 0;
    RREP(i , 17 , 0){
        int to = now + (1 << i);
        if(to < gd && a[to].A <= lim) now = to; 
    }
    return (a[now].A <= lim && now < gd) ? ma[now] : -200000;
}
int G(int lim , int gd){
    int now = 0;
    RREP(i , 17 , 0){
        int to = now + (1 << i);
        if(to < gd && b[to].A <= lim) now = to;
    }
    return (b[now].A <= lim && now < gd) ? mb[now] : -200000;
}
int32_t main(){
    cin >> n >> m >> k;
    REP(i , n){
        int q , w ; char c;
        cin >> q >> w >> c;
        if(c == 'C') a[apo++] = mp(w , q);
        if(c == 'D') b[bpo++] = mp(w , q);
    }
    sort(a , a + apo);
    sort(b , b + bpo);
    ma[0] = a[0].B , mb[0] = b[0].B;
    REPNM(i , 1 , apo) ma[i] = max(a[i].B , ma[i - 1]);
    REPNM(i , 1 , bpo) mb[i] = max(b[i].B , mb[i - 1]);
    int ans = 0;
    ans = max(ans , F(m , apo) + G(k , bpo));
    REP(i , apo){
        if(m - a[i].A >= 0) ans = max(ans , a[i].B + F(m - a[i].A , i));
    }
    REP(i , bpo){
        if(k - b[i].A >= 0) ans = max(ans , b[i].B + G(k - b[i].A , i));
    }
    cout << ans << "\n" ;
    return 0;
}