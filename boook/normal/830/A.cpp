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
#define int long long
#define MAX 3000
#define INF 0x3f3f3f3f


int n , m , to;
int p[MAX] , k[MAX];
int judge(int now){
    int po = 1;
    REP(i , 1 , m + 1){
        if(po <= n){
            int tma = p[po];
            if(abs(tma - k[i]) + abs(k[i] - to) <= now) po ++;
        }
    }
    if(po == n + 1) return 1;
    return 0;
}
int32_t main(){
    cin >> n >> m >> to;
    REP(i , 1 , n + 1) cin >> p[i];
    REP(i , 1 , m + 1) cin >> k[i];
    sort(p + 1 , p + 1 + n);
    sort(k + 1 , k + 1 + m);
    int ans = -1;
    RREP(i , 40 , 0){
        int tmp = ans + (1LL << i);
        if(judge(tmp) == 0) ans = tmp;
    }
    cout << ans + 1 << endl;
    return 0;
}