#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
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

int n , mod;
int sum = 0 , pin = 0;
int ppow(int a , int k){
    if(k == 0) return 1 % mod;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
vector<int> x;
int32_t main(){
    cin >> mod >> n;
    x.resize(n);
    REP(i , 0 , n) cin >> x[i];
    REP(i , 0 , n) sum = (sum + x[i]) % mod;
    REP(i , 0 , n) pin = (pin + x[i] * x[i]) % mod;
    if(n == 1) return cout << x[0] << " " << 1 << endl , 0;
    // DB4("sum = " , sum , "pin = " , pin);
    sort(ALL(x));
    REP(i , 1 , n){
        int d = x[i] - x[0];
        int fr = (sum + mod - n * (n - 1) / 2 * d % mod) * ppow(n , mod - 2) % mod;

        int aa = n * fr % mod * fr % mod;
        int bb = n * (n - 1) * (n + n - 1) / 6 % mod * d % mod * d % mod;
        int cc = n * (n - 1) % mod * fr % mod * d % mod;
        int val = (aa + bb + cc) % mod;
        // DB4("d = " , d , "fr = " , fr);
        // DB4("val = " , val , "\n" , "");

        if(val == pin){
            vector<int> sol;
            REP(j , 0 , n) sol.pb((fr + d * j) % mod);
            sort(ALL(sol));
            if(sol == x) return cout << fr << " " << d << endl , 0;
            // else {
            //     assert(0);
            // }
        }
    }
    cout << -1 << endl;
    return 0;
}