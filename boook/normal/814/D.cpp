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
#define int long long
#define MAX 1010

#define INF 0x3f3f3f3f

typedef pair<int , PII> PIII;
int n , use[MAX];
PIII x[MAX];
VI v[MAX];
int IN(int q , int w){
    int tmp = x[q].A * x[q].A;
    int Q = x[q].B.A - x[w].B.A;
    int W = x[q].B.B - x[w].B.B;
    int dis = Q * Q + W * W;
    if(tmp >= dis) return 1;
    return 0;
}
long double pi = 3.1415926535897932384626433 , ans = 0;
void DFS(int now , int dep){
    long double tmp = x[now].A;
    if(dep % 2 == 1 && dep != 0) ans += tmp * tmp * pi;
    else if(dep != 0) ans -= tmp * tmp * pi;
    for(auto to : v[now]) DFS(to , dep + 1);
}
int bb[MAX];
int32_t main(){
    cin >> n;
    REP(i , n) cin >> x[i].B.A >> x[i].B.B >> x[i].A;
    sort(x , x + n);
    REP(i , n){
        RREP(j , i - 1 , 0){
            if(bb[j]) continue;
            if(IN(i , j)){
                v[i].pb(j) , use[j] = 1;
                bb[j] = 1;
            }
        }
    }
    REP(i , n) if(use[i] == 0){
        // DB4(i , x[i].A , x[i].B.A , x[i].B.B);
        long double tmp = x[i].A;
        ans += tmp * tmp * pi;
        // DBGG("ans = " , ans);
        DFS(i , 0) ;
    }
    printf("%0.9Lf\n", ans);
    return 0;
}