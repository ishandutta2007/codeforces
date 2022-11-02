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

int n , m , x[MAX];
int F(int power){
    // DBGG("power = " , power);
    PII now = mp(0 , 0);
    RREP(i , n , 1){

        if(x[i] == 0) continue;
        if(power <= i) return 0;
        if(now.A > m) return 0;

        if(now.B == power) now.A++ , now.B = 0;

        if(now.B == 0) now.B += i;


        if(power - now.B >= x[i]) now.B += x[i];
        else {
            int lat = x[i] - (power - now.B);
            now.A ++ , now.B = 0;
            int per = power - i;
            now.A += lat / per;
            lat -= (lat / per) * per;
            if(lat > 0) now.B += lat + i;
        }
    }
    // DBGG(now.A , now.B);
    if(now.A == m){
        if(now.B == 0) return 1;
        else return 0;
    }
    else {
        if(now.A < m) return 1;
        else return 0;
    }
}
int32_t main(){
    // cout << (1LL << 50) << endl;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    int ans = 0 , cnt = 0;
    REP(i , 1 , n + 1) if(x[i] != 0) cnt ++;
    if(cnt == 0) {
        cout << 0 << endl;
        return 0;
    }
    else {
        // DBGG("F(5) = " , F(5));
        RREP(i , 50 , 0){
            int to = ans + (1LL << i);
            if(F(to) == 0) ans = to;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}