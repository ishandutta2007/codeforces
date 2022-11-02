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
#define MAX 2900
#define INF 0x3f3f3f3f
#define AC 87
#define mod 100000000000007LL

string a , b;
vector<PII> cc;
int32_t main(){
    IOS;
    cin >> a >> b;
    REP(i , 0 , a.size()){
        int tmp = 0;
        REP(j , i , a.size()){
            tmp = (tmp * AC + a[j]) % mod;
            cc.pb(mp(tmp , (i + 1) * 10000 + j + 1));
        }
    }
    int asiz = a.size() , bsiz = b.size();
    reverse(ALL(a));

    REP(i , 0 , a.size()){
        int tmp = 0 , cnt = 1;
        REP(j , i , a.size()){
            tmp = (tmp * AC + a[j]) % mod;
            cc.pb(mp(tmp , (asiz - i) * 10000 + asiz - j));
        }
    }

    sort(ALL(cc));


    int po = 0;
    vector<int> ans;
    while(po < b.size()){
        int tmp = b[po] , cnt = 1;
        PII ok = *lower_bound(ALL(cc) , mp(tmp , 0LL));

        if(ok.A != tmp){
            cout << "-1" << endl;
            return 0;
        } po ++;
        ans.pb(ok.B);

        while(1){
            tmp = (tmp * AC + b[po]) % mod;
            ok = *lower_bound(ALL(cc) , mp(tmp , 0LL));
            if(ok.A == tmp) ans.back() = ok.B;
            else break;
            po ++;
        }
    }

    cout << ans.size() << endl;
    for(auto now : ans) cout << now / 10000 << " " << now % 10000 << endl;
    return 0;
}