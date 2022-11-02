/*input
2 1 1
aa
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
#define int long long
#define INF 0x3f3f3f3f
#define mod 1000000007LL

vector<vector<int>> mul(vector<vector<int>> a , vector<vector<int>> b){
    vector<vector<int>> ans(60 , vector<int>(60 , 0));
    REP(i , 0 , 60) REP(j , 0 , 60) REP(k , 0 , 60)
        ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;
    return ans;
}
vector<vector<int>> ppow(vector<vector<int>> a , int k){
    if(k == 1) return a;
    if(k % 2 == 0) return ppow(mul(a , a) , k >> 1);
    if(k % 2 == 1) return mul(ppow(mul(a , a) , k >> 1) , a);
}
vector<vector<int>> a(60 , vector<int>(60));
int n , m , k;
string s;
int TR(char c){
    if('a' <= c && c <= 'z') return c - 'a' + 1;
    if('A' <= c && c <= 'Z') return c - 'A' + 27;
    assert(0);
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    if(n == 1) return cout << m << endl , 0;
    REP(i , 1 , m + 1) REP(j , 1 , m + 1) a[i][j] = 1;
    REP(i , 1 , k + 1){
        cin >> s;
        a[TR(s[1])][TR(s[0])] = 0;
    }
    a = ppow(a , n - 1);
    int ans = 0;
    REP(i , 1 , m + 1) REP(j , 1 , m + 1)
        ans = (ans + a[i][j]) % mod;
    cout << ans << endl;
    return 0;
}