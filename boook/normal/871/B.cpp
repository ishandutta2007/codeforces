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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , x[MAX];
int a[MAX] , b[MAX] , sol[MAX] , use[MAX] , check[MAX];
vector<int> v;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 0 , n){
        cout << "? " << i << " " << i << endl;
        fflush(stdout);
        cin >> a[i];
        if(a[i] == -1) exit(0);
    }
    REP(i , 0 , n - 1){
        cout << "? " << i + 1 << " " << i << endl;
        fflush(stdout);
        cin >> b[i];
        if(b[i] == -1) exit(0);
    }
    int cnt = 0;
    REP(ii , 0 , n){
        MEM(use , 0);
        int ok = 1;
        sol[0] = ii;
        check[0] = ii ^ a[0];
        use[ii] = 1;

        int tmp = ii;
        REP(j , 1 , n){
            tmp ^= a[j - 1] ^ b[j - 1];
            sol[j] = tmp;
            check[j] = tmp ^ a[j];
            if(sol[j] >= n || check[j] >= n){
                ok = 0;
                break;
            }
            if(use[sol[j]]){
                ok = 0;
                break;
            }
            else use[sol[j]] = 1;
        }
        REP(i , 0 , n) if(check[sol[i]] != i) ok = 0;
        if(ok){
            cnt ++;
            if(v.size() == 0) REP(j , 0 , n) v.pb(sol[j]);
            // REP(i , 0 , n) cout << sol[i] << " " ; cout << endl;
        }
    }
    cout << "!" << endl;
    cout << cnt << endl;
    for(auto to : v) cout << to << " " ; cout << endl;
    return 0;
}