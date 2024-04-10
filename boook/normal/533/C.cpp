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

int a , b , c , d;
int32_t main(){
    cin >> a >> b >> c >> d;
    int val = 0;
    while(c > 0 && d > 0){
        if(c - 1 <= a && d - 1 <= b){
            int tmp = a - (c - 1) + b - (d - 1);
            if(tmp == val + 1) break;
            val ++ , c-- , d --;
        }
        else val ++ , c-- , d --;
    }
    val += c + d;
    if(val < a + b) cout << "Vasiliy" << endl;
    else cout << "Polycarp" << endl;
    return 0;
}