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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m , k , x[MAX];
VI a , b;
int alen , blen;

int32_t main(){
    cin >> n >> m >> k;
    REP(i , n) cin >> x[i];
    REP(i , n) 
        if(x[i] & 1) a.pb(x[i]);
        else b.pb(x[i]);
    alen = a.size() , blen = b.size();
    int odd = m - k;
    if(alen < odd) return puts("NO");
    else if((alen - odd) % 2 == 1) return puts("NO");
    else {
        // DBGG("here" , "");
        int tmp = alen - odd;
        int qq = tmp / 2;
        if(qq + blen < k) return puts("NO");
        else if(k == 0){
            puts("YES");
            int po = 0;
            REP(i , odd){
                if(i == odd - 1){
                    int ttmp = alen - po + blen;
                    cout << ttmp << " ";
                    for(auto j : b) cout << j << " " ;
                    REPNM(j , po , alen) cout << a[j] << " " ;
                    cout << "\n";
                }
                else cout << "1 " << a[po ++] << "\n";
            }
        }
        else {
            puts("YES");
            REP(i , alen){
                if(i < tmp) b.pb(a[i]);
                else cout << "1 " << a[i] << "\n";
            }
            blen = b.size();
            int po = 0;
            REP(i , k){
                int tmd = b[po];
                if(i == k - 1){
                    cout << blen - po << " ";
                    while(po < blen) cout << b[po++] << " ";
                    puts("");
                }
                else if(tmd & 1){
                    cout << "2 ";
                    cout << b[po] << " " << b[po + 1] << "\n" , po += 2;
                }
                else {
                    cout << "1 " << b[po++] << "\n";
                }
            }
        }
    }
    return 0;
}