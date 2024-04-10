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
#define MAX 
#define INF 0x3f3f3f3f

int n , asum = 0 , bsum = 0 , last = 0 , ans;
VI a , b;
int32_t main(){

    int n;
    cin >> n;
    REP(i , n){
        int tmp;
        cin >> tmp;
        if(tmp > 0) last = 1;
        else last = 2;
        if(tmp > 0) a.pb(tmp) , asum += tmp;
        if(tmp < 0) b.pb(tmp * -1) , bsum += tmp * -1;
    }
    if(asum != bsum){
        if(asum > bsum) ans = 1;
        else ans = 2;
    }
    else {
        int ok = 0 , bok = 0;
        if(a.size() != b.size()){
            if(a.size() > b.size()) ans = 1 , ok = 1;
            else ans = 2 , ok = 1;
        }
        int tmc = min(a.size() , b.size());
        REP(i , tmc){
            if(a[i] > b[i]) ans = 1 , ok = 1 , bok = 1;
            if(a[i] < b[i]) ans = 2 , ok = 1 , bok = 1;
            if(bok) break;
        }
        if(ok == 0) ans = last;        
    }

    if(ans == 1) puts("first");
    else puts("second");
    return 0;
}