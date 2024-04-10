#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200000
#define INF 0x3f3f3f3f

int n , x[MAX];

int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n) cin >> x[i];

    PII cnt = mp(-1 , 0);
    REP(i , 0 , n)
        if(x[i] & 1) cnt.A = i , cnt.B ++;

    int ans = x[0];
    REP(i , 0 , n) ans = __gcd(ans , x[i]);
    
    if(cnt.B > 1){
        cout << 0 << endl;
        REP(i , 0 , n) REP(j , 0 , x[i]) cout << char(i + 'a');
        cout << endl;
    }
    else if(cnt.B == 1){
        ans = 0;
        REP(i , 0 , n){
            if(i == cnt.A) ans = __gcd(ans , x[i]);
            if(i != cnt.A) ans = __gcd(ans , x[i] / 2);
        }
        cout << ans << endl;
        deque<int> dq;
        REP(i , 0 , n){
            REP(j , 0 , x[i]){
                if(j % 2 == 0) dq.push_front(i);
                if(j % 2 == 1) dq.push_back(i);
            }
        }
        string tmp , re;
        REP(i , 0 , n) REP(j , 0 , x[i] / ans / 2) tmp += i + 'a';
        re = tmp; reverse(ALL(re));
        tmp += 'a' + cnt.A;
        tmp += re;
        REP(i , 0 , ans) cout << tmp ;
        cout << endl;
    }
    else {
        cout << ans << endl;
        string tmp , re;
        REP(i , 0 , n){
            REP(j , 0 , x[i] / ans){
                tmp += i + 'a';
            }
        }
        re = tmp , reverse(ALL(re));
        REP(i , 0 , ans) cout << ((i % 2 == 0) ? tmp : re) ;
        cout << endl;
    }
    
    return 0;
}