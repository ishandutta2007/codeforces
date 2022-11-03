#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; ++ i)
#define A first
#define B second
#define mp make_pair
#define pb push_back
#define PII pair<int , int>
#define ALL(i) i.begin() , i.end()
#define MEM(i , j) memset(i , j , sizeof i)
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///-----------------------------------------------------------------------------
#define int long long
#define MAX 1000090
#define INF 0x3f3f3f3f

int n , m , ans[MAX] , tas[MAX];
PII x[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , m + 1) cin >> x[i].A >> x[i].B;
    REP(i , 1 , m + 1){
        REP(j , 1 , m + 1) if(i != j){
            int a = x[i].A; int b = x[i].B; int c = x[j].A; int d = x[j].B;
            if(d != b && b * (c - a) % (d - b) == 0){
                int tmp = a - b * (c - a) / (d - b);
                if(1 <= tmp && tmp <= n)
                    tas[tmp] ++ , ans[tmp] = max(ans[tmp] , tas[tmp]);
            }
        }
        REP(j , 1 , m + 1) if(i != j){
            int a = x[i].A; int b = x[i].B; int c = x[j].A; int d = x[j].B;
            if(d != b && b * (c - a) % (d - b) == 0){
                int tmp = a - b * (c - a) / (d - b);
                if(1 <= tmp && tmp <= n)
                    tas[tmp] = 0;
            }
        }
    }
    // REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    int cnt = 0;
    REP(i , 1 , n + 1) cnt += ans[i] + 1;
    cout << cnt << endl;
    return 0;
}