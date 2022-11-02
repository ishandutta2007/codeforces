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
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
typedef long long LL;
#define int long long
#define MAX 70
#define INF 0x3f3f3f3f

int n , m;
VPII v , sol;
void ADD(int q , int w , int e){
    if(w > e) return ;
    if(q != n) ADD(q + 1 , w * 2 , e * 2 + 1);
    else {
        v.pb(mp(w , 1)) , v.pb(mp(e + 1 , -1));
    }
}
void solveinit(){
    sort(ALL(v));
    int now = v[0].B;
    REPNM(j , 1 , v.size()){
        if(v[j].A != v[j - 1].A && now == m + 1){
            if(v[j - 1].A <= v[j].A - 1)
                sol.pb(mp(v[j - 1].A , v[j].A - 1));
        }
        now += v[j].B;
    }

    // REPNM(i , 1 , n + 1){
    //     DBGG("i = " , i);
    //     for(auto j : can[i]) cout << j.A << "--" << j.B << "  " ; 
    //     cout << endl;
    // }

}
int32_t main(){
    cin >> n >> m;
    ADD(1 , 1 , 1);
    REP(i , m){
        int q , w , e , r;
        cin >> q >> w >> e >> r;
        if(r == 0) ADD(q , (1LL << (q - 1)) , w - 1) , ADD(q , e + 1 , (1LL << q) - 1);
        if(r == 1) ADD(q , w , e);
    }
    solveinit();
    if(sol.empty()) cout << "Game cheated!\n" ;
    else if(sol.size() == 1 && sol[0].A == sol[0].B) cout << sol[0].A << "\n";
    else cout << "Data not sufficient!\n" ;
    return 0;
}