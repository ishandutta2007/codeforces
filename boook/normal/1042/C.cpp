/*input
4
0 0 0 0
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200090
#define INF 1e14

int n , x[MAX] , e[MAX];

int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    int cnt = 0 , big = -INF , idx = 0;
    REP(i , 1 , n + 1){
        if(x[i] < 0){
            cnt ++;
            big = max(big , x[i]);
            if(big == x[i]) idx = i;
        }
    }
    vector<int> no , oth;
    if(cnt % 2 == 1 && idx != 0) no.pb(idx);
    REP(i , 1 , n + 1) if(x[i] == 0) no.pb(i);
    if(no.size() == n) no.pop_back();
    sort(ALL(no));
    for(auto to : no) e[to] = 1;
    REP(i , 1 , no.size()){
        cout << "1 " << no[i - 1] << " " << no[i] << endl;
    }
    if(no.size()) cout << "2 " << no.back() << endl;
    REP(i , 1 , n + 1) if(e[i] == 0) oth.pb(i);
    REP(i , 1 , oth.size()){
        cout << "1 " << oth[i - 1] << " " << oth[i] << endl;
    }
    return 0;
}