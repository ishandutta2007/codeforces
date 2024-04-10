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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , no[MAX][2];
vector<int> sol;
int32_t main(){
    IOS;
    cin >> n >> m;
    srand(time(NULL));
    REP(i , 0 , m){
        int q , w;
        cin >> q >> w;
        if(no[q][0] == 0) no[q][0] = w;
        else no[q][1] = w;

        if(no[w][0] == 0) no[w][0] = q;
        else no[w][1] = q;
    }
    REP(i , 1 , n + 1) sol.pb(i);
    int tiems = 100000;
    REP(i , 0 , tiems){
        random_shuffle(ALL(sol));
        int ok = 1;
        REP(j , 0 , m){
            if(ok == 0) break;
            if(m == n && j + 1 == m){
                if(no[sol[j]][0] == sol[0]) ok = 0;
                if(no[sol[j]][1] == sol[0]) ok = 0;
            }
            else {
                if(no[sol[j]][0] == sol[j + 1]) ok = 0;
                if(no[sol[j]][1] == sol[j + 1]) ok = 0;
            }
        }
        if(ok){
            REP(j , 0 , m){
                if(m == n && j + 1 == m){
                    cout << sol[j] << " " << sol[0] << endl;
                }
                else cout << sol[j] << " " << sol[j + 1] << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}