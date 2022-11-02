#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300
#define INF 0x3f3f3f3f

int n , po , dp[MAX];
vector<int> v[MAX];
map<string , int> cc;
int TR(string s){
    REP(i , 0 , s.size()){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    }
    if(cc.find(s) == cc.end()) return cc[s] = po ++;
    else return cc[s];
}
int DFS(int now){
    if(dp[now] != -1) return dp[now];
    int tmp = 1;
    for(auto to : v[now]) tmp = max(tmp , DFS(to) + 1);
    return dp[now] = tmp;
}
int32_t main(){
    cin >> n;
    REP(i , 0 , n){
        string a , b , c;
        cin >> a >> b >> c;
        int id1 = TR(a) , id2 = TR(c);
        v[id1].pb(id2);
        // DBGG(id1 , id2);
    }
    MEM(dp , -1);
    int ans = 0;
    REP(i , 0 , po) ans = max(ans , DFS(i));
    cout << ans << endl;
    return 0;
}