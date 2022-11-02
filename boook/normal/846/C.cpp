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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f

int n , x[MAX] , pre[MAX];

int32_t main(){
    IOS , cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) pre[i] = pre[i - 1] + x[i];

    int val = -1000000000000000 , a , b , c;
    REP(mid , 1 , n + 2){
        int p = 1 , q = mid;
        REP(i , 1 , mid + 1){
            int v1 = pre[i - 1] - (pre[mid - 1] - pre[i - 1]);
            int v2 = pre[p - 1] - (pre[mid - 1] - pre[p - 1]);
            if(v1 > v2) p = i;
        }
        REP(i , mid , n + 2){
            int v1 = pre[i - 1] - pre[mid - 1] - (pre[n] - pre[i - 1]);
            int v2 = pre[q - 1] - pre[mid - 1] - (pre[n] - pre[q - 1]);
            if(v1 > v2) q = i;
        }
        int v1 = pre[p - 1] - (pre[mid - 1] - pre[p - 1]);
        int v2 = pre[q - 1] - pre[mid - 1] - (pre[n] - pre[q - 1]);
        if(v1 + v2 > val){
            val = v1 + v2;
            a = p - 1 , b = mid - 1 , c = q - 1;
        }
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}