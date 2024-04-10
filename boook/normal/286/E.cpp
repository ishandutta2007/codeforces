/*input
5 1000000
461841 586609 795281 856613 923682
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define cplx pair<double , double>
#define MAX (1 << 21)
#define INF 0x3f3f3f3f

const double PI = acos(-1);
cplx operator + (const cplx x ,const cplx y){ return mp(x.A + y.A , x.B + y.B); }
cplx operator - (const cplx x ,const cplx y){ return mp(x.A - y.A , x.B - y.B); }
cplx operator * (const cplx x ,const cplx y){
    return mp(x.A * y.A - x.B * y.B , x.B * y.A + x.A * y.B); }

cplx tmp[MAX] , w[MAX];
int nn = (1 << 21) , base = 21;
void FFT(cplx x[MAX]){
    int siz = 0 , pat = nn / 2 - 1;
    RREP(i , base - 1 , 0){
        REP(j , 0 , nn){
            int fr = j >> i , ba = j & pat;
            int a = ((fr & siz) << 1 | 0) << i | ba;
            int b = ((fr & siz) << 1 | 1) << i | ba;
            tmp[j] = x[a] + w[fr << i] * x[b];
        }
        memcpy(x , tmp , sizeof tmp);
        siz = (siz << 1 | 1) , pat >>= 1;
    }
}
void IFFT(cplx x[MAX]){
    FFT(x);
    reverse(x + 1 , x + nn);
    REP(i , 0 , nn) x[i].A /= nn;
}
void solveinit(){
    REP(i , 0 , MAX) w[i].A = cos(PI * 2 * i / nn);
    REP(i , 0 , MAX) w[i].B = sin(PI * 2 * i / nn);
}
int n , m;
set<int> cc;
cplx x[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1){
        int in; cin >> in;
        cc.insert(in);
        x[in] = mp(1 , 0);
    }
    solveinit();
    FFT(x);
    REP(i , 0 , nn) x[i] = x[i] * x[i];
    IFFT(x);

    REP(i , 1 , m + 1) if(round(x[i].A) > 0){
        if(cc.find(i) == cc.end()){
            return cout << "NO" << endl , 0;
        }
        else cc.erase(i);
    }
    cout << "YES" << endl;
    cout << cc.size() << endl;
    for(auto to : cc) cout << to << " " ; cout << endl;
    // REP(i , 0 , nn) if(round(x[i].A) > 0) cout << i << " "; cout << endl; 

    return 0;
}