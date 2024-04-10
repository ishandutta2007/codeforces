/*input
3
#apple
#apple
#fruit
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 500900
#define INF 0x3f3f3f3f

int n , tag[MAX];
string s[MAX];
int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> s[i];
    int ans = 0;
    RREP(i , n - 1 , 1){
        int pre = i - 1 , now = i;
        int sml = min(s[pre].size() , s[now].size()) , ok = 0;
        REP(j , 0 , sml){
            if(s[pre][j] < s[now][j]){
                ok = 1;
                break;
            }
            else if(s[pre][j] > s[now][j]){
                while(s[pre].size() > j) s[pre].pop_back() , ans ++;
                ok = 1;
                break;
            }
        }
        if(ok == 0){
            while(s[pre].size() > s[now].size()) s[pre].pop_back() , ans ++;
        }
    }
    REP(i , 0 , n) cout << s[i] << endl;
    return 0;
}