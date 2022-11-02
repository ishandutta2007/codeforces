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
    int cnt = 0 , i = 0;
    while(i + 1 < s.size()){
        if(cnt == 0 && s[i] == 'A' && s[i + 1] == 'B') cnt ++ , i += 2;
        else if(cnt == 1 && s[i] == 'B' && s[i + 1] == 'A'){
            cout << "YES" << endl;
            return 0;
        }
        else i ++;
    }

    cnt = 0 , i = 0;
    while(i + 1 < s.size()){
        if(cnt == 0 && s[i] == 'B' && s[i + 1] == 'A') cnt ++ , i += 2;
        else if(cnt == 1 && s[i] == 'A' && s[i + 1] == 'B'){
            cout << "YES" << endl;
            return 0;
        }
        else i ++;
    }
    cout << "NO" << endl;

    return 0;
}