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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , w[MAX] , h[MAX];
int pre[MAX] , suf[MAX] , sum[MAX];

int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> w[i] >> h[i];

    REP(i , 1 , n + 1) sum[i] = sum[i - 1] + w[i];
    REP(i , 1 , n + 1) pre[i] = max(pre[i - 1] , h[i]);
    RREP(i , n , 1) suf[i] = max(suf[i + 1] , h[i]);

    REP(i , 1 , n + 1){
        int tma = sum[n] - w[i];
        int tmb = max(pre[i - 1] , suf[i + 1]);
        cout << tma * tmb << " ";
    } cout << endl; 
    return 0;
}