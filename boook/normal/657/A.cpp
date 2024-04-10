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

int n , m , k;
int32_t main(){
    // use k + 1
    cin >> n >> m >> k;
    if(m > k + k) cout << -1 << endl;
    else if(k == 1 && m == 1 && n > 2) cout << -1 << endl;
    else {
        int las = m - k;
        REP(i , 2 , 2 + k){
            cout << i - 1 << " " << i << endl;
        }
        int pre = 1;
        REP(i , 2 + k , 2 + k + las){
            cout << pre << " " << i << endl;
            pre = i;
        }
        if(k == 1){
            REP(i , m + 2 , n + 1) cout << 1 << " " << i << endl;
        }
        else {
            REP(i , m + 2 , n + 1) cout << 2 << " " << i << endl;
        }
    }
    return 0;
}