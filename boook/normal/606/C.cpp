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
#define MAX 200000
#define INF 0x3f3f3f3f


int n , x[MAX] , use[MAX];
int can[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1){
        use[x[i]] ++;
        if(use[x[i] + 1] == 0) can[x[i]] = 1;
    }
    int po = 0 , mm = 0;
    while(po <= n){
        int now = po;
        while(now + 1 <= n && can[now]) now ++;
        mm = max(mm , now - po + 1);
        po = now + 1;
    }
    cout << n - mm << endl;
    return 0;
}