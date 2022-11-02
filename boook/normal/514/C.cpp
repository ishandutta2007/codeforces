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
#define MAX 600900
#define INF 0x3f3f3f3f
#define AC 37
#define BC 517
#define mod 1000000009LL

int n , m;
string s;
set<int> cc[MAX];
PII pp[MAX];
int TR(PII now){
    return now.A * 1000000000LL + now.B;
}
int32_t main(){

    pp[0] = mp(1 , 1);
    REP(i , 1 , MAX){
        pp[i].A = pp[i - 1].A * AC % mod;
        pp[i].B = pp[i - 1].B * BC % mod;
    }

    cin >> n >> m;

    REP(times , 0 , n){
        cin >> s;
        PII tmp = mp(0 , 0);
        REP(i , 0 , s.size()){
            tmp.A = (tmp.A * AC + s[i]) % mod;
            tmp.B = (tmp.B * BC + s[i]) % mod;
        }
        int po = 0;
        RREP(i , s.size() - 1 , 0){
            PII now = tmp;
            now.A -= pp[po].A * s[i];
            now.B -= pp[po].B * s[i];
            now.A = (now.A % mod + mod) % mod;
            now.B = (now.B % mod + mod) % mod;
            for(auto j : {'a' , 'b' , 'c'}){
                if(j == s[i]) continue;
                PII qq = now;
                qq.A = (qq.A + pp[po].A * j) % mod;
                qq.B = (qq.B + pp[po].B * j) % mod;
                cc[s.size()].insert(TR(qq));
            }
            po ++;
        }
    }


    REP(times , 0 , m){
        cin >> s;
        PII tmp = mp(0 , 0);
        REP(i , 0 , s.size()){
            tmp.A = (tmp.A * AC + s[i]) % mod;
            tmp.B = (tmp.B * BC + s[i]) % mod;
        }
        if(cc[s.size()].find(TR(tmp)) != cc[s.size()].end())
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}