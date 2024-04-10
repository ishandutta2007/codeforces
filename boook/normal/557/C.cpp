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
// #define DBGG(i,j)     cout << i << " " << j << endl
// #define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 100000000000000LL

int ans = INF;
int n , cnt[MAX] , pre[MAX];
PII x[MAX];

int32_t main(){
    cin >> n;
    map<int , int> cc;
    REP(i , 0 , n) cin >> x[i].A , cc[x[i].A] ++;
    REP(i , 0 , n) cin >> x[i].B;
    int po = 0 , trashsum = 0;

    sort(x , x + n);
    
    RREP(i , n - 1 , 0) pre[i] = pre[i + 1] + x[i].B;

    int helppo = 0;

    for(auto to : cc){
        while(po < n && x[po].A < to.A) cnt[x[po].B] ++ , trashsum += x[po].B , po++;
        int sum = to.B - 1 , tmp = 0;
        RREP(i , 200 , 0){
            if(sum > cnt[i]) tmp += cnt[i] * i , sum -= cnt[i];
            else tmp += sum * i , sum = 0;
        }
        tmp = trashsum - tmp;
        // DBGG("tmp = " , tmp);
        while(helppo < n && x[helppo].A <= to.A) helppo++;
        tmp += pre[helppo];
        ans = min(ans , tmp);
    }
    cout << ans << endl;
    return 0;
}