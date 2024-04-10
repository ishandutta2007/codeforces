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
#define MAX 300090
#define INF 0x3f3f3f3f

int n;
class djs{
public:
    int x[MAX];
    void init(){ REP(i , 0 , n) x[i] = i; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
}ds;
int32_t main(){
    IOS;
    cin >> n;
    int cnt = 0 , now = 1 , ans = 0;
    stack<int> cc;
    ds.init();
    vector<int> tmp;
    REP(i , 0 , n + n){
        string s;
        int q;
        cin >> s;
        if(s == "remove"){
            int th = cc.top(); cc.pop();
            if(ds[th] == ds[now]) now ++;
            else {
                ans ++ , now ++;
                REP(j , 1 , tmp.size()) ds.Union(tmp[j] , tmp[j - 1]);
                tmp.clear();
                if(cc.size()) tmp.pb(cc.top());
            }
        }
        else {
            cin >> q;
            cc.push(q);
            tmp.pb(q);
        }
    }
    cout << ans << endl;
    return 0;
}