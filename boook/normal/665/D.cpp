/*input
2
83 14
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 2000900
#define INF 0x3f3f3f3f

int no[MAX] , p[MAX] , po = 0;
void solveinit(){
    no[0] = no[1] = 1;
    REP(i , 2 , MAX){
        if(no[i] == 0) p[po ++] = i;
        REP(j , 0 , po){
            if(i * p[j] >= MAX) break;
            no[i * p[j]] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
int n , x[MAX] , cnt[MAX];
vector<int> ans;
int32_t main(){
    solveinit();
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) cnt[x[i]] ++;

    REP(i , 1 , n + 1){
        REP(j , i + 1 , n + 1){
            if(ans.size() == 2) break;
            if(no[x[i] + x[j]] == 0){
                ans.pb(x[i]);
                ans.pb(x[j]);
            }
        }
    }
    if(ans.size() == 0){
        ans.pb(x[1]);
    }
    int id = 0;
    REP(i , 1 , n + 1){
        if(no[x[i] + 1] == 0 && x[i] != 1) id = x[i];
    }
    if(cnt[1] && id && cnt[1] + 1 > ans.size()){
        cout << cnt[1] + 1 << endl;
        REP(i , 1 , cnt[1] + 1) cout << 1 << " ";
        cout << id << endl;
    }
    else if(cnt[1] > ans.size()){
        cout << cnt[1] << endl;
        REP(i , 1 , cnt[1] + 1) cout << 1 << " ";
        cout << endl;
    }
    else {
        cout << ans.size() << endl;
        for(auto to : ans) cout << to << " " ; cout << endl;
    }
    return 0;
}