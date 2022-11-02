/*input
8 8
(()(()))
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
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

int n , k , r[MAX] , ans[MAX];
string s;
int32_t main(){
    IOS;
    cin >> n >> k >> s;
    stack<int> st;
    REP(i , 0 , s.size()) r[i] = -1;
    REP(i , 0 , s.size()){
        if(s[i] == '(') st.push(i);
        else r[st.top()] = i , st.pop();
    }
    int las = (n - k) / 2;
    REP(i , 0 , s.size()) if(r[i] != -1 && las > 0) las -- , r[i] = -1;
    REP(i , 0 , s.size()){
        if(r[i] != -1) ans[i] = 1 , ans[r[i]] = 2;
    }
    REP(i , 0 , s.size()){
        if(ans[i] == 1) cout << "(";
        if(ans[i] == 2) cout << ")";
    }
    cout << endl;
    return 0;
}