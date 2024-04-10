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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n;
string s , x[MAX];
PII val[MAX] , tmp[MAX];

int pp(int now){
    int ans = 1 , res = 10;
    while(now){
        if(now & 1) ans = ans * res % mod;
        res = res * res % mod;
        now >>= 1;
    }
    return ans;
}

int32_t main(){

    cin >> s >> n;
    REP(i , 0 , n) cin >> x[i];
    REP(i , 0 , 10) val[i] = mp(i , 10);

    RREP(i , n - 1 , 0){
        REP(j , 0 , 10) tmp[j] = val[j];
        int res = x[i][0] - '0' , cnt = 0 , sum = 1;
        RREP(j , x[i].size() - 1 , 0){
            if(x[i][j] == '>') break;
            int now = x[i][j] - '0';
            cnt = (cnt + val[now].A * sum) % mod;
            sum = sum * val[now].B % mod;
        }
        tmp[res] = mp(cnt , sum);
        REP(j , 0 , 10) val[j] = tmp[j];
    }
    // REP(i , 0 , 10){
    //     DB4("i = " , i , val[i].A , val[i].B);
    // }
    int ans = 0 , sum = 1;
    RREP(i , s.size() - 1 , 0){
        int now = s[i] - '0';
        ans = (ans + val[now].A * sum) % mod;
        sum = sum * val[now].B % mod;
        // DB4("ans = " , ans , "sum = " , sum);
    }
    cout << ans << endl;
    return 0;
}