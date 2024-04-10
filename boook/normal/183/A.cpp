#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; ++ i)
#define A first
#define B second
#define mp make_pair
#define pb push_back
#define PII pair<int , int>
#define ALL(i) i.begin() , i.end()
#define MEM(i , j) memset(i , j , sizeof i)
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///-----------------------------------------------------------------------------
#define int long long
#define MAX
#define INF 0x3f3f3f3f


int n;
string s;
map<string , int> cc;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> s , cc[s] ++;
    int v1 = 1 + cc["UL"] + cc["DR"] + cc["ULDR"];
    int v2 = 1 + cc["UR"] + cc["DL"] + cc["ULDR"];
    cout << v1 * v2 << endl;
    return 0;
}