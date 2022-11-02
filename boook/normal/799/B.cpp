#include <bits/stdc++.h>
using namespace std;
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
#define int long long
#define MAX 200100
#define INF 0x3f3f3f3f

int n , val[MAX] , c[MAX][2] , m;
priority_queue<PII> pq[3];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , n) cin >> val[i];
    REP(i , n) cin >> c[i][0];
    REP(i , n) cin >> c[i][1];
    REP(i , n){
        pq[c[i][0] - 1].push(mp(-val[i] , i));
        pq[c[i][1] - 1].push(mp(-val[i] , i));
    }
    cin >> m;
    REP(i , m){
        int now , ans = -1;
        cin >> now; now--;
        while(pq[now].size()){
            PII to = pq[now].top();
            pq[now].pop();
            if(val[to.B] != -1){
                ans = val[to.B] , val[to.B] = -1;
                break;
            }
        }
        cout << ans << " ";
    }
    cout << "\n" ;
    return 0;
}