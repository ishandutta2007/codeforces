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
#define MAX 1000
#define INF 0x3f3f3f3f

int n;
string s[MAX];
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
int IN(int a , int b){
    return (a >= 0 && a < n && b >= 0 && b < n && s[a][b] == 'o');
}
int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> s[i];
    REP(i , 0 , n){
        REP(j , 0 , n){
            int cnt = 0;
            REP(k , 0 , 4){
                if(IN(i + X[k] , j + Y[k])) cnt ++;
            }
            if(cnt & 1) {cout << "NO" << endl; return 0;}
        }
    }
    cout << "YES" << endl;
    return 0;
}