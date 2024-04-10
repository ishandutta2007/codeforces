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
    cin >> s;
    vector<int> v;
    int ok = 0;
    REP(i , 0 , s.size()){
        int now = s[i] - '0';
        if(now % 2 == 0) ok = 1;
    }
    if(ok == 0) {
        cout << -1 << endl;
        return 0;
    }
    else {
        int lat = s[s.size() - 1] - '0';
        REP(i , 0 , s.size()){
            int now = s[i] - '0';
            if(now % 2 == 0){
                if(now < lat){
                    swap(s[i] , s.back());
                    cout << s << endl;
                    return 0;
                }
            }
        }
        RREP(i , s.size() - 1 , 0){
            int now = s[i] - '0';
            if(now % 2 == 0){
                if(now > lat){
                    swap(s[i] , s.back());
                    cout << s << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}