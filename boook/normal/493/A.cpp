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
#define MAX 1000
#define INF 0x3f3f3f3f

string a , b;
int n;
int q[MAX] , w[MAX];
char qq[MAX] , ww[MAX];
VI ans;
map<int , int> cc;
int cmp(int tma , int tmb){
    return q[tma] < q[tmb];
}
int32_t main(){
    cin >> a >> b;
    cin >> n;
    REP(i , n){
        cin >> q[i] >> qq[i] >> w[i] >> ww[i];
        int tmp = w[i];
        if(qq[i] == 'a') tmp *= -1;
        if(cc.find(tmp) == cc.end()) cc[tmp] = 0;
        if(ww[i] == 'r'){
            if(cc[tmp] < 2) ans.pb(i);
            cc[tmp] = 2;
        }
        else {
            if(cc[tmp] == 1) ans.pb(i);
            cc[tmp] ++;
        }
    }
    sort(ALL(ans) , cmp);
    REP(i , ans.size()){
        int now = ans[i];
        if(qq[now] == 'h') cout << a << " ";
        else cout << b << " ";
        cout << w[now] << " " << q[now] << "\n";
    }
    return 0;
}