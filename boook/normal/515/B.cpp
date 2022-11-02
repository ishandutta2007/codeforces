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
#define MAX 200
#define INF 0x3f3f3f3f

int n , m , tmp , cnt;
bool a[MAX] , b[MAX];

int32_t main(){
    cin >> n >> m;

    cin >> tmp;
    REP(i , 0 , tmp) cin >> cnt , a[cnt] = 1;
    cin >> tmp;
    REP(i , 0 , tmp) cin >> cnt , b[cnt] = 1;

    REP(i , 0 , 8000000){
        tmp = a[i % n] | b[i % m];
        a[i % n] = b[i % m] = tmp;
    }
    REP(i , 0 , n) if(a[i] == 0) {
        cout << "No" << endl;
        return 0;
    }
    REP(i , 0 , m) if(b[i] == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}