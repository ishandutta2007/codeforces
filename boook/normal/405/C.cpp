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
#define endl "\n"
///------------------------------------------------------------
#define MAX 1010
#define INF 0x3f3f3f3f

int n , x[MAX][MAX];
inline int rit(){
    char c = getchar();
    int res = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
    return res;
}
int32_t main(){
    n = rit();
    REP(i , 0 , n) REP(j , 0 , n) x[i][j] = rit();
    int ans = 0;
    REP(i , 0 , n) REP(j , 0 , n) ans = (ans ^ (x[j][i] & x[i][j]));
    n = rit();
    int a , b , c;
    REP(i , 0 , n){
        a = rit();
        if(a != 3){
            b = rit();
            ans = ans ^ 1;
        }
        else putchar(ans + '0');
    }
    puts("");
    return 0;
}