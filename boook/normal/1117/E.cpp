/*input

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string query(string now){
    cout << "? " << now << endl;
    fflush(stdout);
    string ans; cin >> ans;
    return ans;
}
string t , a , b , c , aa , bb , cc , ans;

map<string , vector<int>> v;
int32_t main(){
    IOS;
    cin >> t;
    int n = t.size();

    a = b = c = ans = t;
    REP(i , 0 , n) a[i] = 'a' + (i % 26);
    aa = query(a);

    v.clear();
    REP(i , 0 , n) v[a.substr(i , 1)].pb(i);
    for(auto to : v){
        int pos = 0;
        for(auto idx : to.S) b[idx] = 'a' + pos , pos = (pos + 1) % 26;
    }
    bb = query(b);
    
    v.clear();
    REP(i , 0 , n) v[a.substr(i , 1) + b.substr(i , 1)].pb(i);
    for(auto to : v){
        int pos = 0;
        for(auto idx : to.S) c[idx] = 'a' + pos , pos = (pos + 1) % 26;
    }
    cc = query(c);

    map<int , int> fin;
    REP(i , 0 , n) fin[a[i] * 10000 + b[i] * 100 + c[i]] = i;
    REP(i , 0 , n) ans[fin[aa[i] * 10000 + bb[i] * 100 + cc[i]]] = t[i];
    cout << "! " << ans << endl;
    return 0;
}