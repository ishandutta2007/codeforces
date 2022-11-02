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
#define MAX 200000
#define INF 0x3f3f3f3f
#define mod 1000000009LL

int n , ans = 0;
PII a[MAX];
map<PII , int> hold , x;
set<int> pq;
void check(PII now){
    if(x.find(now) == x.end()) return ;
    int id = x[now];
    if(a[id].A == -1) return;
    int ok = 1;
    REP(j , -1 , 2){
        PII tmp = mp(now.A + j , now.B + 1);
        if(x.find(tmp) != x.end() && a[x[tmp]].A == -1) continue; 
        if(hold.find(tmp) != hold.end() && hold[tmp] <= 1) ok = 0; 
    }
    if(ok) pq.insert(id) ;//, DBGG("push = " , id);
    else pq.erase(id);
}
int32_t main(){
    cin >> n;
    REP(i , 0 , n){
        int q , w;
        cin >> q >> w;
        a[i] = mp(q , w);
        x[mp(q , w)] = i;
    }
    REP(i , 0 , n){
        int q = a[i].A , w = a[i].B;
        REP(j , -1 , 2){
            if(x.find(mp(q + j , w + 1)) != x.end())
                hold[mp(q + j , w + 1)] ++;
        }
    }
    REP(i , 0 , n){
        int ok = 1;
        REP(j , -1 , 2){
            PII tmp = mp(a[i].A + j , a[i].B + 1);
            if(x.find(tmp) == x.end()) continue;
            if(hold.find(tmp) != hold.end() && hold[tmp] <= 1) ok = 0; 
        }
        if(ok) pq.insert(i) ;//, DBGG("INSERT = " , i);
    }

    int ty = 0;
    while(pq.size()){
        auto tt = pq.begin();
        if(ty == 0) tt = pq.end() , tt--;
        int val = *tt; pq.erase(tt);
        ans = (ans * n + *tt) % mod;
        // DBGG("now at = " , *tt);
        REP(j , -1 , 2){
            PII good = mp(a[val].A + j , a[val].B + 1);
            if(hold.find(good) != hold.end()) hold[good] --;
        }
        PII tmp = a[val];
        a[val] = mp(-1 , -1);

        REP(j , -1 , 2) check(mp(tmp.A + j , tmp.B + 1));
        REP(j , -3 , 4) check(mp(tmp.A + j , tmp.B));
        REP(j , -1 , 2) check(mp(tmp.A + j , tmp.B - 1));
        ty = 1 - ty;
    }

    cout << ans << endl;

    return 0;
}