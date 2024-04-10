/*input
?aa?
ab
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
#define MAX 2000000
#define INF 0x3f3f3f3f

string a , b;
int cnt[MAX] , ok = 0;
vector<int> sol;
int32_t main(){
    IOS;
    cin >> a >> b;
    REP(i , 0 , a.size()){
        if(a[i] == '?') ok ++;
        else cnt[a[i] - 'a'] ++;
    }
    while(ok){
        REP(i , 0 , b.size()){
            if(ok == 0) break;
            if(cnt[b[i] - 'a']) cnt[b[i] - 'a'] --;
            else sol.pb(b[i] - 'a') , ok --;
        }
    }
    REP(i , 0 , a.size()){
        if(a[i] != '?') cout << a[i];
        else cout << (char)(sol.back() + 'a') , sol.pop_back();
    }
    cout << endl;
    return 0;
}