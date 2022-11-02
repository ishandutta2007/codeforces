#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
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
#define MAX 6000
#define INF 0x3f3f3f3f
#define AC 514514
#define mod 1000000007
typedef long long LL;


string a , b;
LL p[MAX];
LL h[MAX];
LL m[MAX];
int32_t main(){
    IOS;
    cin >> a >> b;
    REP(i , a.size()) p[i + 1] = (p[i] * AC + a[i]) % mod;
    REP(i , b.size()) h[i + 1] = (h[i] * AC + b[i]) % mod;
    m[0] = 1;
    REPNM(i , 1 , a.size() + 10) m[i] = m[i - 1] * AC % mod;
    REPNM(i , 1 , a.size() + 1){
        // DBGG("now = " , i);
        int aok = 0 , bok = 0;
        gp_hash_table<int , int> ma , mb;
        REPNM(j , i , a.size() + 1){
            int tmp = ((p[j] - p[j - i] * m[i]) % mod + mod) % mod;
            ma[tmp] ++;
        }
        REPNM(j , i , b.size() + 1){
            int tmp = ((h[j] - h[j - i] * m[i]) % mod + mod) % mod;
            mb[tmp] ++;
        }
        for(auto tmp : ma){
            if(mb.find(tmp.A) != mb.end()) bok = 1;
            if(mb[tmp.A] == 1 && tmp.B == 1) aok = 1;
        }
        if(bok == 0) {
            cout << "-1\n" ;
            return 0;
        }
        if(aok == 1){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}