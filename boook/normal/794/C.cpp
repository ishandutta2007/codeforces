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
#define MAX 400000
#define INF 0x3f3f3f3f

string a , b;
int apo , bpo;
char ans[MAX];
int32_t main(){
    cin >> a >> b;
    sort(ALL(a));
    sort(ALL(b));
    // cout << a << endl;
    // cout << b << endl;

    apo = 0 , bpo = b.size() - 1;
    int ta = 0 , tb = b.size() - 1;
    REP(i , a.size()){
        if(i % 2 == 0){
            if(a[apo] >= b[bpo]){
                vector<char> q , w;
                REPNM(j , i , a.size()){
                    if(j % 2 == 0) q.pb(a[apo++]);
                    if(j % 2 == 1) w.pb(b[bpo--]);
                }
                int wpo = w.size() - 1;
                int qpo = q.size() - 1;
                int tnow = i;
                RREP(j , a.size() - 1 , i){
                    if(tnow % 2 == 0) ans[j] = q[qpo--];
                    if(tnow % 2 == 1) ans[j] = w[wpo--];   
                    tnow ++;
                }
                break;
            }
            else ans[ta++] = a[apo++];
        }
        if(i % 2 == 1){
            if(a[apo] >= b[bpo]){
                vector<char> q , w;
                REPNM(j , i , a.size()){
                    if(j % 2 == 0) q.pb(a[apo++]);
                    if(j % 2 == 1) w.pb(b[bpo--]);
                }
                int wpo = w.size() - 1;
                int qpo = q.size() - 1;
                int tnow = i;
                RREP(j , a.size() - 1 , i){
                    if(tnow % 2 == 0) ans[j] = q[qpo--];
                    if(tnow % 2 == 1) ans[j] = w[wpo--];   
                    tnow ++;
                }
                break;
            }
            else ans[ta++] = b[bpo--];
        }
    }
    REP(i , a.size()) cout << ans[i] ; cout << endl;
    return 0;
}