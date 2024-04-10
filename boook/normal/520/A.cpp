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
#define MAX 50
#define INF 0x3f3f3f3f

int use[MAX];

int32_t main(){
    int n;
    string s;
    cin >> n >> s;
    REP(i , 0 , s.size()){
        if(s[i] >= 'a' && s[i] <= 'z') use[s[i] - 'a'] = 1;
        else use[s[i] - 'A'] = 1;
    }

    REP(i , 0 , 26) if(use[i] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}