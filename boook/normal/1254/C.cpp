/*input
10
-3 0
3 0
-1 -2
1 2
-1 2
1 -2
-2 -1
-2 1
2 1
2 -1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

// PII x[10000];

// int cross(PII a , PII b){
//     return a.F * b.S - a.S * b.F;
// }
// PII operator - (PII a , PII b){
//     return mp(b.F - a.F, b.S - a.S);
// }

int query1(int a , int b , int c){
    // return abs(cross(x[b] - x[a] , x[c] - x[a]));
    cout << "1 " << a << " " << b << " " << c << endl;
    cout.flush(); int ret; cin >> ret; return ret;
}
int query2(int a , int b , int c){
    // int val = cross(x[b] - x[a] , x[c] - x[a]);
    // cout << a << " " << b << " " << c << " " << val << endl;
    // cout << c << " " << ((val > 0) - (val < 0)) << endl;
    // return (val > 0) - (val < 0);

    cout << "2 " << a << " " << b << " " << c << endl;
    cout.flush(); int ret; cin >> ret; return ret;
}

vector<int> v1 , v2;
vector<int> h1 , h2;
vector<int> d1 , d2;

int cmp1(int a , int b){ return h2[a] < h2[b]; }
int cmp2(int a , int b){ return h2[a] > h2[b]; }
int cmp3(int a , int b){ return h1[a] < h1[b]; }
int cmp4(int a , int b){ return h1[a] > h1[b]; }

int n;
int32_t main(){

    cin >> n;
    // REP(i , 1 , n + 1) cin >> x[i].F >> x[i].S;


    REP(i , 3 , n + 1){
        int ans = query2(1 , 2 , i);
        if(ans ==  1) v1.pb(i);
        if(ans == -1) v2.pb(i);
    }

    // for(auto to : v1) cout << to << " "; cout << endl;
    // for(auto to : v2) cout << to << " "; cout << endl;

    for(auto to : v1) h1.pb(query1(1 , 2 , to)); 

    for(auto to : v2) h2.pb(query1(1 , 2 , to)); 

    PII big1 = mp(-1 , -1);
    PII big2 = mp(-1 , -1);

    REP(i , 0 , v1.size()) big1 = max(big1, mp(h1[i] , v1[i]));
    REP(i , 0 , v2.size()) big2 = max(big2, mp(h2[i] , v2[i]));

    for(auto to : v1) {
        if(to == big1.S) d1.pb(0);
        else d1.pb(query2(1 , big1.S , to)); 
    }
    for(auto to : v2){
        if(to == big2.S) d2.pb(0);
        else d2.pb(query2(1 , big2.S , to)); 
    }

    vector<int> p1 , p2;

    // solve v2
    // cout << "D2" ;
    // for(auto to : d2) cout << to << " "; cout << endl;
    // for(auto to : v2) cout << to << " "; cout << endl;

    vector<int> ans;

    ans.pb(1);

    if(v2.size()){
        p1.clear(); p2.clear();

        REP(i , 0 , v2.size()) if(v2[i] != big2.S) {
            if(d2[i] == -1) p1.pb(i);
            else p2.pb(i);
        }
        sort(p1.begin(), p1.end(), cmp1);
        sort(p2.begin(), p2.end(), cmp2);

        // for(auto to : p1) cout << v2[to] << " "; cout << endl;
        // for(auto to : p2) cout << v2[to] << " "; cout << endl;


        for(auto to : p1) ans.pb(v2[to]);
        ans.pb(big2.S);
        for(auto to : p2) ans.pb(v2[to]);
    }
    ans.pb(2);
    if(v1.size()){
        p1.clear(); p2.clear();

        REP(i , 0 , v1.size()) if(v1[i] != big1.S) {
            if(d1[i] == -1) p1.pb(i);
            else p2.pb(i);
        }
        sort(p1.begin(), p1.end(), cmp3);
        sort(p2.begin(), p2.end(), cmp4);

        for(auto to : p1) ans.pb(v1[to]);
        ans.pb(big1.S);
        for(auto to : p2) ans.pb(v1[to]);
    }

    cout << 0 ;
    for(auto to : ans) cout << " " << to ; cout << endl;
    return 0;
}