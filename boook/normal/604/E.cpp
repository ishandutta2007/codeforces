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
#define int long long
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m;
int x[MAX];
int F(int now){
    if(now == 1) return 1;
    if(now == 2) return 0;
    if(now == 3) return 1;
    if(now == 4) return 2;
    if(now & 1) return 0;
    int tmp = F(now / 2);
    if(tmp == 0) return 1;
    if(tmp == 1) return 2;
    return 1;
}
int G(int now){
    if(now == 1) return 1;
    else if(now == 2) return 2;
    else if(now % 2 == 0) return 1;
    return 0;
}
int32_t main(){
    cin >> n >> m;
    m %= 2;
    REP(i , 1 , n + 1) cin >> x[i];
    int ans = 0;
    if(m == 0){
        REP(i , 1 , n + 1){
            ans ^= G(x[i]);
        }
    }
    else {
        REP(i , 1 , n + 1){
            ans ^= F(x[i]);
        }
    }
    if(ans == 0) cout << "Nicky" << endl;
    else cout << "Kevin" << endl;
    return 0;
}