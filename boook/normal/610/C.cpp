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
#define MAX 10000
#define INF 0x3f3f3f3f

string s[MAX];
int32_t main(){
    IOS;
    s[0] += "++";
    s[1] += "+*";
    int now = 2;
    while(now < 300){
        REP(i , 0 , now) s[i] += s[i];
        REP(i , now , now + now){
            s[i] += s[i - now];
            REP(j , now , now + now){
                if(s[i][j] == '+') s[i][j] = '*';
                else s[i][j] = '+';
            }
        }
        now *= 2;
    }
    int n;
    cin >> n;
    n = (1 << n);
    REP(i , 0 , n){
        REP(j , 0 , n) cout << s[i][j];
        cout << endl;
    }
    return 0;
}