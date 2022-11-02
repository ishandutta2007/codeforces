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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define AC 517
#define BC 8787
#define mod 1000000007LL

int n;
string a , b;
PII val[MAX] , pre[MAX] , h[MAX];

int32_t main(){
    cin >> n >> a >> b;

    h[0] = mp(1 , 1);
    REP(i , 1 , MAX){
        h[i].A = h[i - 1].A * AC % mod;
        h[i].B = h[i - 1].B * BC % mod;
    }

    PII tmp = mp(0 , 0);
    RREP(i , b.size() - 1 , 0){
        if(b[i] == 'N') b[i] = 'S';
        else if(b[i] == 'S') b[i] = 'N';
        else if(b[i] == 'W') b[i] = 'E';
        else if(b[i] == 'E') b[i] = 'W';   
        tmp.A = (tmp.A * AC + b[i]) % mod;
        tmp.B = (tmp.B * BC + b[i]) % mod;
        val[i] = tmp;
        // DB4("val = " , tmp.A , tmp.B , "");
    }
    // DBGG("why = " , b);
    tmp = mp(0 , 0);
    REP(i , 0 , a.size()){
        tmp.A = (tmp.A * AC + a[i]) % mod;
        tmp.B = (tmp.B * BC + a[i]) % mod;
        pre[i + 1] = tmp;
        // DB4("pre[i] = " , tmp.A , tmp.B , "");
    }
    int cnt = 1;
    // DBGG("hrer" , "");
    RREP(i , a.size() - 1 , 0){
        PII now;
        now.A = ((pre[n - 1].A - pre[i].A * h[cnt].A) % mod + mod) % mod;
        now.B = ((pre[n - 1].B - pre[i].B * h[cnt].B) % mod + mod) % mod;
        // DB4("now = " , now.A , now.B , "");
        if(now == val[i]){
            cout << "NO" << endl;
            return 0;
        }
        cnt ++;
    }
    cout << "YES" << endl;
    return 0;
}