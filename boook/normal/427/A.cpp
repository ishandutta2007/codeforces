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
#define MAX 2000000
#define INF 0x3f3f3f3f

int n , x[MAX] , cnt , ans = 0;

int32_t main(){
    IOS;
    cin >> n;
    REP(i , n){
        cin >> x[i];
        if(x[i] < 0){
            x[i] = -x[i];
            int tmp = min(cnt , x[i]);
            cnt -= tmp;
            ans += x[i] - tmp;
        }
        else cnt += x[i];
    }
    cout << ans << endl;
    return 0;
}