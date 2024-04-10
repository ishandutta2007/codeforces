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
#define MAX 60
#define INF 0x3f3f3f3f

int use[MAX] , n , m;
string s;

int32_t main(){
    cin >> n >> m >> s;
    REP(i , 0 , 26) use[i] = i;
    REP(i , 0 , m){
        char q , w;
        cin >> q >> w;
        int a = q - 'a' , b = w - 'a';
        REP(j , 0 , 26){
            if(use[j] == a) use[j] = b;
            else if(use[j] == b) use[j] = a;
        }
    }
    REP(i , 0 , s.size()){
        cout << char(use[s[i] - 'a'] + 'a');
    }
    cout << endl;
    return 0;
}