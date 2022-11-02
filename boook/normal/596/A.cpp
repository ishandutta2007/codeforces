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
#define MAX 
#define INF 0x3f3f3f3f

int n;
PII x[10];

int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> x[i].A >> x[i].B;
    if(n == 1){
        cout << "-1" << endl;
    }
    else if(n == 2){
        if(x[0].A != x[1].A && x[0].B != x[1].B){
            cout << abs(x[1].A - x[0].A) * abs(x[0].B - x[1].B) << endl;
        }
        else cout << -1 << endl;
    }
    else if(n == 3){
        int a = 0 , b = 0;
        REP(i , 0 , 3) REP(j , i + 1 , 3){
            a = max(a , abs(x[i].A - x[j].A));
            b = max(b , abs(x[i].B - x[j].B));
        }
        cout << a * b << endl;
    }
    else if(n == 4){
        int a = 0 , b = 0;
        REP(i , 0 , 4) REP(j , i + 1 , 4){
            a = max(a , abs(x[i].A - x[j].A));
            b = max(b , abs(x[i].B - x[j].B));
        }
        cout << a * b << endl;
    }
    return 0;
}