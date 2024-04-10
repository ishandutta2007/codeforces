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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , leaf;
int x[MAX] , pa[MAX];
vector<int> v[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> leaf;
    REP(i , 1 , m + 1) cin >> x[i];
    int po = 2;
    v[0].pb(1);
    REP(i , 1 , m + 1){
        REP(j , 1 , x[i] + 1) v[i].pb(po ++);
    }
    int sml = v[m].size();
    REP(i , 0 , m){
        int a = v[i].size() , b = v[i + 1].size();
        sml += max(a - b , 0);
    }
    REP(i , 1 , m + 1){
        REP(j , 0 , v[i].size()){
            if(j < v[i - 1].size()) pa[v[i][j]] = v[i - 1][j];
            else pa[v[i][j]] = v[i - 1][0];
        }
    }
    if(leaf < sml) return cout << -1 << endl , 0;
    REP(i , 1 , m + 1){
        if(sml == leaf) break;
        REP(j , 0 , v[i].size()){
            if(sml == leaf) break;
            if(pa[v[i][j]] != v[i - 1][0]){
                pa[v[i][j]] = v[i - 1][0];
                sml ++;
            }
        }
    }
    if(leaf != sml) cout << -1 << endl , 0;
    else {
        cout << n << endl;
        REP(i , 2 , n + 1) cout << i << " " << pa[i] << endl;
    }
    return 0;
}