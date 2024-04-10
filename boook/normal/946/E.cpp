/*input
4
89
88
1000
28923845
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
#define MAX 
#define INF 0x3f3f3f3f

string GET(string now){
    string tmp = now;
    reverse(ALL(tmp));
    return now + tmp;
}
int v[10] , no = 0;
int t;
string s , p;
int DFS(int now , int no , int top){
    // DB4(now , no , top , p);
    int las = int(s.size()) - now;
    if(no > las) return 0;
    if(now == s.size()){
        if(top == 0) return 0;
        return cout << p << endl , 1;
    }
    if(no == las){
        int from = top == 0 ? s[now] - '0' : 9;
        RREP(i , from , 0) if(v[i]){
            p[now] = '0' + i;
            v[i] ^= 1;
            if(DFS(now + 1 , no - 1 , top || i != from)) return 1;
            v[i] ^= 1;
        }
        return 0;
    }
    else {
        int from = top == 0 ? s[now] - '0' : 9;
        RREP(i , from , 0){
            p[now] = '0' + i;
            no += v[i] == 0;
            no -= v[i] == 1;
            v[i] ^= 1;
            if(DFS(now + 1 , no , top || i != from)) return 1;
            no += v[i] == 0;
            no -= v[i] == 1;
            v[i] ^= 1;
        }
        return 0;
    }
}
int32_t main(){
    IOS;
    cin >> t;
    REP(times , 1 , t + 1){
        cin >> s;
        REP(i , 0 , 10) v[i] = 0;

        int ok = 0;
        if(s[0] != '1' || s.back() > '1') ok = 1;
        REP(i , 1 , s.size() - 1) if(s[i] != '0') ok = 1;
        if(ok == 0){
            int len = s.size();
            REP(i , 2 , s.size()) cout << 9; cout << endl;
        }
        else p = s , DFS(0 , 0 , 0);
    }
    return 0;
}