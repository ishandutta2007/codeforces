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


int32_t main(){
    int n;
    string s , b;
    cin >> n >> s;
    b = s;b[0] ++;
    REP(i , 0 , b.size()){
        if(b[i] == '2'){
            if(i + 1 != b.size()) b[i + 1]++;
            b[i] = '0';
        }
    }
    int cnt = 0;
    REP(i , 0 , b.size())
        if(b[i] != s[i]) cnt ++;
    cout << cnt << endl;
    return 0;
}