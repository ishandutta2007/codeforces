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
#define MAX 25
#define INF 0x3f3f3f3f

string x[MAX] , a[MAX];
int tr[MAX];

int32_t main(){
    int n , q , nn; 
    cin >> n;
    REP(i , n) cin >> x[i] , tr[i] = i;
    cin >> q;
    int ans = INF , anspo = -1;
    REP(times , q){
        sort(tr , tr + n);
        cin >> nn;
        REP(j , nn) cin >> a[j];
        string to;

        do{
            int po = -1;
            REP(i , n){
                if(po == nn) break;
                po ++;  
                if(po == nn) break;

                while(po < nn && x[tr[i]] != a[po]){
                    po ++;
                }
            }
            if(po != nn){
                int cnt = 0;
                REP(i , n) REPNM(j , i + 1 , n) if(tr[i] > tr[j]) cnt ++;
                if(cnt < ans) ans = min(ans , cnt) , anspo = times + 1;
            }
        }while(next_permutation(tr , tr + n));
    }
    if(ans == INF) puts("Brand new problem!");
    else {
        cout << anspo << endl;
        int sum = n * (n - 1) / 2 - ans + 1;
        cout << "[:" ; 
        REP(i , sum) cout << "|";
        cout << ":]" << endl;
    }
    return 0;
}