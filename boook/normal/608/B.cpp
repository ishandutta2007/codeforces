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
#define MAX 400000
#define INF 0x3f3f3f3f

string a , b;
int val[MAX] , pre[MAX] , ans;
int32_t main(){
    cin >> a >> b;
    REP(i , 0 , b.size()) if(b[i] == '1') val[i + 1] = 1;

    REP(i , 1 , b.size() + 1) pre[i] = pre[i - 1] + val[i];

    int siz = b.size();
    siz = siz - (int)(a.size()) + 1;
    int len = b.size() - a.size() + 1;
    REP(i , 0 , a.size()){
        int tmp = pre[siz ++] - pre[i];
        if(a[i] == '0') ans += tmp;
        else ans += len - tmp;
    }
    cout << ans << endl;
    return 0;
}