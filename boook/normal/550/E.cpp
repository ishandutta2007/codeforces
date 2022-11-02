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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX];

int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    if(n == 1){
        cout << ((x[n] == 0) ? "YES\n0" : "NO") << endl;
    }
    else if(x[n] == 1){
        cout << "NO" << endl;
        return 0;
    }
    else {
        if(x[n - 1] == 1){
            cout << "YES" << endl;
            REP(i , 1 , n + 1){
                cout << x[i];
                if(i != n) cout << "->" ;
            }
            cout << endl;
            return 0;
        }
        else if(n - 2 <= 0) {cout << "NO" << endl; return 0;}
        else if(x[n - 2] == 0){
            cout << "YES" << endl;
            REP(i , 1 , n - 2) cout << x[i] << "->";
            cout << "(0->0)->0" << endl;
        }
        else {
            int cnt = 1;
            RREP(i , n - 2 , 1) if(x[i] == 0){
                cout << "YES" << endl;
                REP(j , 1 , i) cout << x[j] << "->";
                cout << "(0->(";
                REP(j , i + 1 , n){
                    cout << x[j] ;
                    if(j != n - 1) cout << "->";
                }
                cout << "))->0" << endl;
                return 0;
            }
            cout << "NO" << endl;
        }
    }
    return 0;
}