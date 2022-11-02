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

int n , x[MAX] , a[MAX];
void put(int now){
    RREP(i , 20 , 0) cout << !(!((1 << i) & now)) ; cout << endl;
}
int TR(int now , int to , int hei){

    int nh = 0 , sum = -1;
    RREP(i , 20 , 0) if((1 << i) & now) {
        nh = i; break;
    }
    if(hei >= nh){
        sum = 0;
        REP(i , nh){
            int tma = (1 << (nh - 1 - i)) & now;
            int tmb = (1 << (hei - 1 - i)) & to;
            tma = (tma == 0) ? 0 : 1;
            tmb = (tmb == 0) ? 0 : 1;
            if(tma != tmb) {
                sum = (nh - i) * 2; break;
            }
        }
        sum += (hei - nh);
    }
    else if(nh > hei){
        REP(i , hei){
            int tma = (1 << (nh - 1 - i)) & now;
            int tmb = (1 << (hei - 1 - i)) & to;
            tma = (tma == 0) ? 0 : 1;
            tmb = (tmb == 0) ? 0 : 1;
            if(tma != tmb) {
                sum = (nh - i) + abs(hei - ((nh - ((nh - i)))));
                break;
            }
        }
        if(sum == -1) sum = abs((hei - nh));
    }
    // put(now) , put(to);
    // DB4("hei = " , hei , "nh = " , nh);
    // DBGG("ans = " , sum);
    // cout << "-------\n" ; 
    // exit(0);
    return sum;
}
int32_t main(){
    cin >> n;
    REP(i , n) cin >> x[i];
    REP(i , n){
        a[i] = x[i];
        while(((1 << 20) & a[i]) == 0) a[i] <<= 1;
    }
    int en = a[0];
    REP(i , n) en &= a[i];
    // DBGG("en = " , en);
    int ans = INF , tma = 20;
    while(en > 0){
        int cnt = 0;
        REP(i , n) cnt += TR(x[i] , en , tma);
        en >>= 1 , tma --;
        ans = min(ans , cnt);

    }
    cout << ans << endl;
    return 0;
}