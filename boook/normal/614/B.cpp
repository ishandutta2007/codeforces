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
#define MAX 200000
#define INF 0x3f3f3f3f

int n;
string x[MAX];
string fk;
int F(string val){
    if(val[0] != '1') return 1;
    REP(i , 1 , val.size()) if(val[i] != '0') return 1;
    return 0;
}
int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> x[i];
    REP(i , 0 , n){
        if(x[i] == "0"){
            cout << 0 << endl;
            return 0;
        }
    }
    fk = "1";
    REP(i , 0 , n){
        if(F(x[i]) == 1) fk = x[i] , x[i] = "1";
    }
    int cnt = 0;
    REP(i , 0 , n){
        cnt += (int)(x[i].size()) - 1;
    }
    cout << fk;
    REP(i , 0 , cnt) cout << 0 ;
    cout << endl;
    return 0;
}