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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m;
PII x[MAX];
typedef pair<PII , int> PIII;
__gnu_pbds::priority_queue<PIII , greater<PIII> > pq;
__gnu_pbds::priority_queue<PIII , greater<PIII> >::point_iterator qq[MAX];
VPII ans;
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , n) cin >> x[i].A , x[i].B = i + 1;
    sort(x , x + n);
    if(x[0].A != 0) return puts("-1");
    qq[x[0].B] = pq.push(mp(mp(x[0].A , 0) , x[0].B));
    REPNM(i , 1 , n){
        while(pq.size() && pq.top().A.A != x[i].A - 1) pq.pop();
        if(pq.empty()) return puts("-1");
        PIII tmp = pq.top();
        if(tmp.A.B + 1 == m) pq.pop();
        else pq.modify(qq[tmp.B] , mp(mp(tmp.A.A , tmp.A.B + 1) , tmp.B));
        ans.pb(mp(x[i].B , tmp.B));
        if(m != 1)qq[x[i].B] = pq.push(mp(mp(x[i].A , 1) , x[i].B));
    }
    cout << ans.size() << "\n";
    for(auto i : ans) cout << i.A << " " << i.B << "\n";
    return 0;
}