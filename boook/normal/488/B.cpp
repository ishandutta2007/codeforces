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

int check(vector<int> q){
    sort(ALL(q));
    int a = q[0] + q[1] + q[2] + q[3];
    int b = q[1] + q[2] + q[1] + q[2];
    int c = 4 * (q[3] - q[0]);
    if(a == b && b == c) return 1;
    else return 0;
}
int n , tma , tmp;
int F(vector<int> q){
    tmp = q[0] + q[1] - q[2] , q.pb(tmp);
    if(check(q) == 1 && tmp <= 1000000 && tmp >= 1) return 1;
    q.pop_back();

    tmp = q[0] - q[1] + q[2] , q.pb(tmp);
    if(check(q) == 1 && tmp <= 1000000 && tmp >= 1) return 1;
    q.pop_back();

    tmp = -q[0] + q[1] + q[2] , q.pb(tmp);
    if(check(q) == 1 && tmp <= 1000000 && tmp >= 1) return 1;
    q.pop_back();
    return 0;
}
vector<int> x , y;
int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> tma , x.pb(tma);
    if(n == 0){
        cout << "YES" << endl;
        cout << "1" << endl;
        cout << "1" << endl;
        cout << "3" << endl;
        cout << "3" << endl;
    }
    else if(n == 1){
        cout << "YES" << endl;
        cout << x[0] << endl;
        cout << x[0] * 3 << endl;
        cout << x[0] * 3 << endl;
    }
    else if(n == 2){
        REP(i , 1 , 1000000 + 1){
            x.pb(i);
            if(F(x) == 1){
                cout << "YES" << endl;
                cout << i << endl;
                cout << tmp << endl;
                return 0;
            }
            x.pop_back();
        }
        cout << "NO" << endl;
    }
    else if(n == 3){
        if(F(x) == 1){
            cout << "YES" << endl;
            cout << tmp << endl;
        }
        else cout << "NO" << endl;
    }
    else if(n == 4){
        if(check(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}