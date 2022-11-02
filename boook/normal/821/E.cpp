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
#define MAX 17
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m , c[MAX][MAX];
int CPY(int q[MAX][MAX] , int w[MAX][MAX] , int siz){
    REP(i , 0 , siz + 1) REP(j , 0 , siz + 1){
        q[i][j] = w[i][j];
    }
}
int pp(int q[MAX][MAX] , int w[MAX][MAX] , int siz){
    MEM(c , 0);
    REP(i , 0 , siz + 1){
        REP(j , 0 , siz + 1){
            REP(k , 0 , siz + 1){
                c[i][j] = (c[i][j] + q[i][k] * w[k][j]) % mod;
            }
        }
    }
    CPY(q , c , siz);
}
void mypow(int a[MAX][MAX] , int k , int siz){
    if(k == 1) return;
    int tt[MAX][MAX];
    CPY(tt , a , siz);
    if(k % 2 == 0) {
        pp(a , tt , siz);
        mypow(a , k / 2 , siz);
    }
    else {
        pp(a , tt , siz);
        mypow(a , k / 2 , siz);
        pp(a , tt , siz);   
    }
}
int a[MAX][MAX];
int x[MAX] , ww[MAX];

int32_t main(){
    IOS;
    cin >> n >> m;
    x[0] = 1;
    REP(i , 1 , n + 1){
        int q , w , e;
        cin >> q >> w >> e;
        if(i == n) w = m;
        if(w - q == 0) continue;
        MEM(a , 0);
        REP(j , 0 , e + 1){
            a[j][j] = 1;
            if(j - 1 >= 0) a[j][j - 1] = 1;
            if(j + 1 <= e) a[j][j + 1] = 1;
        }
        // REP(ii , 0 , e + 1){
        //     REP(jj , 0 , e + 1){
        //         cout << a[ii][jj] << " ";
        //     }
        //     cout << endl;
        // }
        mypow(a , w - q , e);
        MEM(ww , 0);
        REP(ii , 0 , e + 1){
            REP(jj , 0 , e + 1){
                ww[ii] = (ww[ii] + a[ii][jj] * x[jj]) % mod;
            }
        }
        MEM(x , 0);
        REP(i , 0 , e + 1) x[i] = ww[i];
    }
    cout << x[0] << endl;
    return 0;
}