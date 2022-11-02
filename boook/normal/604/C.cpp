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

int n;
string s;

int32_t main(){
    cin >> n >> s;
    
    int q = -1 , w = -1;
    REP(i , 1 , s.size()){
        if(s[i] == s[i - 1]){
            q = i;
            break;
        }
    }
    RREP(i , s.size() - 1 , 0){
        if(s[i] == s[i + 1]){
            w = i;
            break;
        }
    }
    if(q != -1){
        if(q > w) w = s.size() - 1;
        REP(i , q , w + 1){
            if(s[i] == '0')s[i] = '1';
            else if(s[i] == '1')s[i] = '0';
        }
    }

    int tmp = -1 , cnt = 0;
    REP(i , 0 , s.size()){
        if(tmp != s[i] - '0') cnt ++ , tmp = s[i] - '0';
    }
    cout << cnt << endl;
    return 0;
}