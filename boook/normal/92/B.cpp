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

string s;
int32_t main(){
    IOS;
    cin >> s;
    int po = int(s.size()) - 1 , ans = 0;
    while(po >= 0){
        if(s[po] == '0') po -- , ans ++;
        else {
            if(po == 0){
                cout << ans << endl;
                return 0;
            }
            while(po >= 0 && s[po] == '1') po -- , ans++;
            if(po == -1) {
                cout << ans + 1 << endl;
                return 0;
            }
            else s[po] = '1' , ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}