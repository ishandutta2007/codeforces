#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 50090
#define INF 0x3f3f3f3f

int x[MAX][10] , ans[MAX] , n , m;

int32_t main(){
    cin >> n >> m;
    REPNM(i , 1 , n + 1) REPNM(j , 1 , m + 1) cin >> x[i][j];
    REPNM(i , 1 , m + 1){
        REPNM(j , 1 , n + 1){
            int tmp = max(ans[j] , ans[j - 1]);
            ans[j] = tmp + x[j][i];
        }
    }
    REPNM(i , 1 , n + 1) cout << ans[i] << " ";
    puts("");
    return 0;
}