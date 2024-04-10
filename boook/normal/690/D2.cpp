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
#define MAX 5000000
#define INF 0x3f3f3f3f
#define mod 1000003

int m[MAX] , mm[MAX];

int ppow(int a , int b){
    if(b == 1) return a;
    if(b % 2 == 0) return ppow(a * a % mod , b / 2);
    if(b % 2 == 1) return ppow(a * a % mod , b / 2) * a % mod;
}
int N , M;
int C(int a , int b){
    return m[a] * mm[b] % mod * mm[a - b] % mod;
}
int32_t main(){
    m[0] = 1;
    REP(i , 1 , MAX) m[i] = m[i - 1] * i % mod;
    REP(i , 0 , MAX) mm[i] = ppow(m[i] , mod - 2);
    cin >> N >> M;
    int ans = 0;
    REP(i , 0 , N + 1){
        ans = (ans + C(i + M - 1 , M - 1)) % mod;
    }
    cout << ans - 1 << endl;
    return 0;
}