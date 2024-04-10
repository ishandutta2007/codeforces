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

int n , m , k;
int x[MAX] , att[MAX];
int32_t main(){
    cin >> n >> m >> k;
    REP(i , 1 , n + 1){
        cin >> x[i];
        att[x[i]] = i;
    }
    int now;
    int ans = 0;
    REP(i , 1 , m + 1){
        cin >> now;
        int pos = att[now];
        if(pos == 1) ans ++;
        else {

            ans += (pos % k == 0) ? pos / k : pos / k + 1;
            int lat = pos - 1;
            int preval = x[lat];
            swap(x[lat] , x[pos]);
            swap(att[now] , att[preval]);
        }
        // DBGG("ans = " , ans);
    }
    cout << ans << endl;
    return 0;
}