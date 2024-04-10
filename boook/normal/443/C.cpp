#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
typedef pair< LL , LL > PLL;
typedef vector< int > VI;
typedef vector< LL > VLL;
typedef vector< PII > VPII;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
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

int n , tmp[MAX] , ok[MAX] , ook[MAX];
string x[MAX];
vector<string> v;
char Z[] = {'R', 'G', 'B', 'Y', 'W'};
int main(){
    RI(n);

    REP(i , n) cin >> x[i] , v.pb(x[i]);
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    // REP(i , v.size()) cout << v[i] << " " ; cout << endl;
    int ans = 100000;
    REPNM(i , 0 , 1024){
    // {
        // int i = 40;
        int now = i , sum = 0;
        REP(j , 10){
            tmp[j] = now % 2;
            sum += now % 2;
            now >>= 1;
        }

        MEM(ok , 0);
        MEM(ook , 0);
        int susseed = 0;

        // {REP(j , 10) cout << tmp[j] << " " ; cout << endl;}
        // DBGG("v.size( = " , v.size() );
        REP(j , 10){
            if(!tmp[j]) continue;
            REP(k , v.size()){
                if(j < 5 && v[k][1] - '1' == j) ok[k] ++;// , cout << "70 " << k << "  " << v[k] << endl;
                else if(v[k][0] == Z[j - 5]) ok[k] ++;
            }
        }
        // {REP(j , v.size()) cout << ok[j] << " " ; cout << endl;}
        REP(k , v.size()) if(ok[k] == 2) ook[k] = 1;// , cout << k << endl;

        VI w , ww;
        REP(j , 10){
            if(!tmp[j]) continue;
            REP(k , v.size()){
                if(ook[k]) continue;
                if(j < 5){
                    if(v[k][1] - '1' == j) w.pb(j) , ww.pb(k);
                } 
                else{
                    if(v[k][0] == Z[j - 5]) w.pb(j) , ww.pb(k); 
                } 
            }
        }
        // cout << "87  " ;REP(i , w.size()) cout << w[i] << " " ; cout << endl;
        sort(ALL(w));
        int las = w.size();
        w.resize(unique(ALL(w)) - w.begin());
        if(las == w.size()){
            REP(l , ww.size()) ook[ww[l]] = 1;
        }

        REP(k , v.size())
            if(ook[k] == 0) susseed ++;      
        if(susseed <= 1)susseed = 1;
        else susseed = 0;
        if(susseed){
            // if(sum < ans){REP(j , 10) cout << tmp[j] << " " ; cout << endl;}
            ans = min(ans , sum);
        }
    }
    printf("%d\n", ans);
    return 0;
}