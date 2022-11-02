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
#define MAX 700900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , aa[MAX];
vector<int> v;
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    priority_queue<PII> pq;
    int ans = 0 , po = m + 1 , sum = 0;
    REP(i , 1 , m + 1){
        ans += sum;
        pq.push(mp(x[i] , i));
        sum += x[i];
    }
    REP(i , 1 , n + 1){
        ans += sum;
        if(po <= n) pq.push(mp(x[po] , po)) , sum += x[po] , po ++ ;
        PII tmp = pq.top(); pq.pop();
        sum -= tmp.A;
        v.pb(tmp.B);
    }
    cout << ans << endl;
    REP(i , 0 , v.size()){
        aa[v[i]] = m + i + 1;
    }
    REP(i , 1 , n + 1) cout << aa[i] << " " ; cout << endl;
    return 0;
}