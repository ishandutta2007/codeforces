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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m;
PII x[MAX] , a[MAX];

int32_t main(){
    cin >> n;
    REPNM(i , 1 , n + 1) cin >> x[i].A >> x[i].B;
    cin >> m;
    REP(i , m) cin >> a[i].A , a[i].B = i + 1;
    sort(a , a + m);
    int sum = 0;
    VPII ans;
    REP(j , m){
        int po = 0 , val = 0;
        REPNM(i , 1 , n + 1){
            if(x[i].A == -1) continue;
            if(x[i].A <= a[j].A && x[i].B > val) po = i , val = x[i].B;
        }
        if(po) ans.pb(mp(po , a[j].B)) , x[po].A = -1 , sum += val;
    }

    cout << ans.size() << " " << sum << "\n";
    for(auto now : ans) cout << now.A << " " << now.B << "\n";
    return 0;
}