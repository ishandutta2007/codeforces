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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int len , now , to;
int vcar , vman;
int carpos , dir;
int32_t main(){
    cin >> len >> now >> to >> vcar >> vman >> carpos >> dir;
    int ans = abs(now - to) * vman , dis = 0;
    int ok = 0;
    while(dis < ans){
        if(carpos == len) dir = -1;
        if(carpos == 0) dir = 1;
        if(carpos == now) ok = 1;
        if(carpos == to && ok){
            ans = min(ans , dis);
            break;
        }
        carpos += dir , dis += vcar;
    }
    cout << ans << endl;
    return 0;
}