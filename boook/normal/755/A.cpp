/*input
4
*/
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
#define MAX 
#define INF 0x3f3f3f3f

int ppow(int a , int k , int mod){
    if(k == 0) return 1 % mod;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1 , mod);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1 , mod) * a % mod;
}
int check(int now){
    REP(i , 0 , 10){
        int tmp = rand() % (now - 1) + 1;
        if(ppow(tmp , now - 1 , now) != 1) return 1;
    }
    return 0;
}
int n;
int32_t main(){
    cin >> n;
    REP(i , 1 , 1001){
        if(check(n * i + 1)){
            return cout << i << endl , 0;
        }
    }
    return 0;
}