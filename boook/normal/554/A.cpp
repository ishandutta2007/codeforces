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
#define MAX 
#define INF 0x3f3f3f3f

set<string> cc;
string s;
int32_t main(){
    cin >> s;
    REP(i , 0 , s.size() + 1){
        string a = s.substr(0 , i);
        string b = s.substr(i , s.size() - i);
        // DBGG(a , b);
        REP(j , 0 , 26){
            string tmp = a;
            tmp += 'a' + j;
            tmp += b;
            cc.insert(tmp);
        }
    }
    cout << cc.size() << endl;
    return 0;
}