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
#define MAX 1009000
#define INF 0x3f3f3f3f

string s;
stack<int> cc;
int to[MAX];
int TR(char c){
    if(c == '<' || c == '{' || c == '['|| c == '(') return 0;
    if(c == '>' || c == '}' || c == ']'|| c == ')') return 1;
    assert(0);
}
int TTR(char c){
    if(c == '<' || c == '>') return 0;
    if(c == '{' || c == '}') return 1;
    if(c == '[' || c == ']') return 2;
    if(c == '(' || c == ')') return 3;
}
int32_t main(){
    MEM(to , -1);
    cin >> s;
    REP(i , 0 , s.size()){
        int ty = TR(s[i]);
        if(ty == 0) cc.push(i);
        else {
            if(cc.empty()) return 0 * puts("Impossible");
            else {
                int tmp = cc.top(); cc.pop();
                to[tmp] = i;
            }
        }
    }
    if(cc.size()) return 0 * puts("Impossible");
    int ans = 0;
    REP(i , 0 , s.size()){
        if(to[i] == -1) continue;
        int u = to[i];
        if(TTR(s[i]) != TTR(s[u])) ans ++;
    }
    cout << ans << endl;
    return 0;
}