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
#define int long long
#define MAX 2020
#define INF 0x3f3f3f3f

int n , x[MAX][MAX];
map<int , int> a , b;
int32_t main(){
    IOS;
    cin >> n;
    REPNM(i , 1 , n + 1)
        REPNM(j , 1 , n + 1)
            cin >> x[i][j];
    REPNM(i , 1 , n + 1){
        REPNM(j , 1 , n + 1){
            if(a.find(i + j) == a.end()) a[i + j] = 0;
            if(b.find(i - j) == b.end()) b[i - j] = 0;
            a[i + j] += x[i][j];
            b[i - j] += x[i][j];  
        }
    }
    int q = 0 , w = 0;
    PII qq , ww;
    REPNM(i , 1 , n + 1){
        REPNM(j , 1 , n + 1){
            int tmp = a[i + j] + b[i - j] - x[i][j];
            if((i + j) % 2 == 0){
                if(tmp >= q) q = tmp , qq = mp(i , j);
            }
            else {
                if(tmp >= w) w = tmp , ww = mp(i , j);
            }
        }
    }
    cout << q + w << "\n" ;
    cout << qq.A << " " << qq.B << " " << ww.A << " " << ww.B << "\n";
    return 0;
}