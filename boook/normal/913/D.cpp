/*input
2 100
2 42
2 58
*/
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , x[MAX] , t[MAX] , sol[MAX] , xxx[MAX];

int cmp1(int a , int b){
    if(t[a] != t[b]) return t[a] < t[b];
    else return x[a] < x[b];
}
int cmp2(int a , int b){
    if(x[a] != x[b]) return x[a] < x[b];
    else return t[a] < t[b];
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i] >> t[i];
    REP(i , 1 , n + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + n , cmp1);
    typedef pair<int , PII> PIII;
    priority_queue<PIII , vector<PIII> , greater<PIII> > pq;
    int ans = 0 , cnt = 0;
    REP(iii , 1 , n + 1){
        int id = sol[iii];
        cnt += t[id];
        pq.push(mp(x[id] , mp(-t[id] , id)));
        while(pq.size()){
            PIII now = pq.top();
            if(now.A < pq.size()) cnt += now.B.A , pq.pop();
            else break;
        }
        if(cnt > m) break;
        else ans = max(ans , (int)pq.size());
    }
    while(pq.size()) pq.pop();
    cnt = 0;
    REP(iii , 1 , n + 1){
        int id = sol[iii];
        cnt += t[id];
        pq.push(mp(x[id] , mp(-t[id] , id)));
        while(pq.size()){
            PIII now = pq.top();
            if(now.A < pq.size()) cnt += now.B.A , pq.pop();
            else break;
        }
        if(cnt > m) break;
        else {
            if(pq.size() == ans){
                cout << ans << endl;
                cout << ans << endl;
                while(pq.size()){
                    PIII now = pq.top(); pq.pop();
                    cout << now.B.B << " ";
                }
                cout << endl;
                return 0;
            }            
        }
    }
    cout << 0 << endl;
    cout << 0 << endl;

    return 0;
}