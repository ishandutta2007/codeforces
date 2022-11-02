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
#define MAX 
#define INF 0x3f3f3f3f

int n , m;
map<int , int> b , s;
vector<PII> fr , ba;
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n){
        string ss;
        int q , w;
        cin >> ss >> q >> w;
        if(ss == "S") s[q] += w;
        if(ss == "B") b[q] += w;
    }
    auto to = b.end();
    REP(i , 0 , m){
        if(to == b.begin()) break;
        to --;
        ba.pb(mp((*to).A , (*to).B));
    }
    to = s.begin();
    if(s.size()){
        REP(i , 0 , min(m , (int)s.size())){
            fr.pb(mp((*to).A , (*to).B));
            to++;
        }
    }
    sort(ALL(fr) , greater<PII>());
    sort(ALL(ba) , greater<PII>());
    for(auto to : fr) cout << "S " << to.A << " " << to.B << endl;
    for(auto to : ba) cout << "B " << to.A << " " << to.B << endl;

    return 0;
}