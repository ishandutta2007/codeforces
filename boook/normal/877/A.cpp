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
#define MAX 5050

string s;
int32_t main(){
    int cnt = 0;
    cin >> s;
    REP(i , 0 , s.size()){
        if(cnt > 1) break;
        string tmp = s.substr(i , 5);
        if(tmp == "Danil") cnt ++;
        if(tmp == "Slava") cnt ++;

        tmp = s.substr(i , 3);
        if(tmp == "Ann") cnt ++;
        tmp = s.substr(i , 4);
        if(tmp == "Olya") cnt ++;
        tmp = s.substr(i , 6);
        if(tmp == "Nikita") cnt ++;
    }
    if(cnt == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}