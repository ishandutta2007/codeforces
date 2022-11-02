#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(unsigned i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(unsigned i = j ; i >=k ; --i)
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
#define MAX 5050
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , k;

long long x[MAX] , a[MAX] , b[MAX] , c[MAX];

int ppow(int a , int b){
    if(b == 0) return 1;
    if(b % 2 == 0) return ppow(a * a % mod , b / 2);
    if(b % 2 == 1) return ppow(a * a % mod , b / 2) * a % mod;
}

int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 1 , n + 1) cin >> x[i];

    if(k == 0){
        REP(i , 1 , n + 1) cout << x[i] << endl;
    }
    else {
        a[1] = 1;
        int fr = k , ba = 1;
        REP(i , 2 , n + 1){
            a[i] = a[i - 1] * fr % mod * ppow(ba , mod - 2) % mod;
            fr ++ , ba ++;
        }

        REP(i , 1 , n + 1){
            long long val = 0;
            RREP(j , i , 1)
                val = (val + a[j] * x[i - j + 1]) % mod;
            cout << val << endl;
        }
        
    }

    return 0;
}