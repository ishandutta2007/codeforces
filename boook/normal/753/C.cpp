/*input

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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 100
#define INF 0x3f3f3f3f

map<string , vector<string>> cc[MAX];
vector<string> v;
int n = 10 , c[MAX];
int calc(string a , string b){
    int v1 = 0 , v2 = 0;
    REP(i , 0 , 4)
        if(a[i] == b[i]) a[i] = '.' , b[i] = '!' , v1 ++;
    REP(i , 0 , 4) REP(j , 0 , 4) if(a[i] == b[j])
        if(a[i] == b[j]) a[i] = '.' , b[j] = '!' , v2 ++;
    return v1 * 10 + v2;
}
int GET(string s){
    cout << s << endl;
    fflush(stdout);
    int v1 , v2;
    cin >> v1 >> v2;
    if(v1 == 4) exit(0);
    else return v1 * 10 + v2;
}
void update(vector<string> &all , string s , int ans){
    vector<string> nxt;
    for(auto to : all) if(calc(s , to) == ans) nxt.pb(to);
    all = nxt;
}
string Find(vector<string> things){
    int sml = INF;
    string way;
    for(auto p : v){
        MEM(c , 0);
        int big = 0;
        for(auto s : things) c[calc(p , s)] ++;
        REP(ii , 0 , 50) big = max(big , c[ii]);
        if(sml > big) sml = big , way = p;
    }
    return way;
}
int32_t main(){
    IOS;
    // cout << calc("2084" , "0128") << endl;
    // return 0;
    REP(i , 0 , 10) REP(j , 0 , 10) if(j != i){
        REP(k , 0 , 10) if(k != i && k != j){
            REP(l , 0 , 10) if(l != i && l != j && l != k){
                string p;
                p += '0' + i , p += '0' + j , p += '0' + k , p += '0' + l;
                v.pb(p);
            }
        }
    }
    string q = "1234";
    int ans = GET(q);
    vector<string> all = v;
    update(all , q , ans);
    REP(i , 0 , 10){
        // for(auto to : all) cout << to << " "; cout << endl;
        if(all.size() == 1) q = all[0];
        else q = Find(all);
        ans = GET(q);
        update(all , q , ans);
    }
    
    return 0;
}