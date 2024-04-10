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
#define INF 0x3f3f3f3f

int n , m;
deque<int> dq;
int32_t main(){
    cin >> n >> m;
    m = min(m , n);
    REP(i , 1 , n + 1){
        int in; cin >> in;
        dq.pb(in);
    }
    int cnt = 0;
    while(1){
        int aa = dq.front(); dq.pop_front();
        int bb = dq.front(); dq.pop_front();
        if(aa > bb){
            cnt ++;
            dq.push_front(aa);
            dq.push_back(bb);
        }
        else {
            cnt = 1;
            dq.push_front(bb);
            dq.push_back(aa); 
        }
        if(cnt == m){
            cout << aa << endl;
            return 0;
        }
    }
    return 0;
}