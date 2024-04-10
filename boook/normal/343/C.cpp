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
#define MAX 100900
#define INF 1000000000000000LL

int n , m;
int a[MAX] , b[MAX];
int judge(int lim){
    int po = 1;
    REP(i , 1 , n + 1){
        int dis = lim , now = a[i];
        if(now <= b[po]){
            while(po <= m && abs(b[po] - now) <= dis){
                dis -= abs(b[po] - now);
                now = b[po];
                po ++;
            }
        }
        else {
            int l = b[po] , r = b[po];
            while(po <= m){
                r = b[po];
                int v1 = abs(now - l) + abs(l - r);
                int v2 = abs(now - r) + abs(r - l);
                // DB4(v1 , v2 , l , r);
                if(min(v1 , v2) <= lim) po ++;
                else break;
            }
        }
    }
    if(po == m + 1) return 1;
    return 0;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , m + 1) cin >> b[i];
    int ans = -1;
    RREP(i , 56 , 0){
        int to = (ans + (1LL << i));
        if(judge(to) == 0) ans = to;
    }
    cout << ans + 1 << endl;
    return 0;
}