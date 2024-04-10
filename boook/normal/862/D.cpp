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
// #define DBGG(i,j)     cout << i << " " << j << endl
// #define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define MAX 10000
#define INF 0x3f3f3f3f

int ans[2];
int n , ffind , all;
void solveinit(){
    string s;
    int a , b;

    REP(i , 0 , n) s += "0";
    cout << "? " << s << endl;
    fflush(stdout);
    cin >> a; all = a;

    s[0] = '1';
    cout << "? " << s << endl;
    fflush(stdout);
    cin >> b;
    if(a < b) ffind = 1 , ans[0] = 1;
    else ffind = 0 , ans[1] = 1; 
}
void solve(){
    string p , s;
    REP(i , 0 , n) p += "0";
    int l = 1;
    // DBGG("ffind = " , ffind);
    RREP(i , 12 , 0){
        int to = l + (1 << i) , tmp;
        // DB4("l = " , l , "to = " , to);
        if(to > n) continue;
        s = p;
        REP(j , l , to) s[j] = '1';
        cout << "? " << s << endl;
        fflush(stdout);
        cin >> tmp;
        if(ffind == 0){
            if(all - tmp == (1 << i)) l = to;
        }
        else {
            if(tmp - all == (1 << i)) l = to;
        }
    }
    ans[ffind] = l + 1;
}
int32_t main(){
    cin >> n;
    solveinit();
    // cout << "----" << endl;
    solve();
    cout << "! " << ans[0] << " " << ans[1] << endl;
    return 0;
}