#include <bits/stdc++.h>
using namespace std;
#define MAX (1 << 20) + 10
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define mid ((l + r) >> 1)
#define int long long
int n , m , nn , one[MAX] , a[MAX] , b[MAX];
string s[MAX];
void solveinit(){
    REP(i , 1 , nn){
        if(i % 2 == 0) one[i] = one[i >> 1];
        if(i % 2 == 1) one[i] = one[i >> 1] + 1;
    }
    REP(i , 0 , nn){
        b[i] = min(one[i] , n - one[i]);
    }
}
void FWT(int now[MAX] , int l , int r){
    if(l == r) return ;
    FWT(now , l , mid + 0);
    FWT(now , mid + 1 , r);
    int lpo = l , rpo = mid + 1;
    while(lpo <= mid){
        now[lpo] = now[lpo] + now[rpo];
        now[rpo] = now[lpo] - now[rpo] - now[rpo];
        lpo ++ , rpo ++;
    }
}
void IFWT(int now[MAX] , int l , int r){
    if(l == r) return ;
    int lpo = l , rpo = mid + 1;
    while(lpo <= mid){
        now[lpo] = (now[lpo] + now[rpo]) / 2;
        now[rpo] = now[lpo] - now[rpo];
        lpo ++ , rpo ++;
    }
    IFWT(now , l , mid + 0);
    IFWT(now , mid + 1 , r);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];
    REP(i , 0 , m){
        int val = 0;
        REP(j , 0 , n) val = val * 2 + s[j][i] - '0';
        a[val] ++;
    }

    nn = (1 << n);
    solveinit();

    FWT(a , 0 , nn - 1) , FWT(b , 0  , nn - 1);
    REP(i , 0 , nn) a[i] = a[i] * b[i];
    IFWT(a , 0 , nn - 1);

    int ans = n * m + 10;
    REP(i , 0 , nn) ans = min(ans , a[i]);
    cout << ans << endl;
    return 0;
}