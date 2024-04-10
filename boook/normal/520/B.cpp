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
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f


int n , m;
map<int , int> cc;
int32_t main(){
    cin >> n >> m;
    queue<PII> qu;
    qu.push(mp(n , 0)) , cc[n] = 0;
    int ans = INF;
    while(qu.size()){
        PII now = qu.front(); qu.pop();
        // DBGG(now.A , now.B);
        int tmp = now.A * 2;
        if(cc.find(tmp) == cc.end()){
            if(tmp <= m)
                cc[tmp] = now.B + 1 , qu.push(mp(tmp , cc[tmp]));
            else {
                ans = min(ans , tmp - m + now.B + 1);
            }
        }
        tmp = now.A - 1;
        if(cc.find(tmp) == cc.end() && tmp > 0)
            cc[tmp] = now.B + 1 , qu.push(mp(tmp , cc[tmp]));
        if(cc.find(m) != cc.end()){
            ans = min(ans , cc[m]);
            cout << cc[m] << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}