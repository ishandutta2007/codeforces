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
#define MAX 200000
#define INF 0x3f3f3f3f

int n , w[MAX];
PII x[MAX];
map<PII , int> cc;
map<int , queue<int> > ma;
vector<int> ans;
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i].A >> x[i].B , cc[x[i]] = i;
    int tmp = 0;

    ma[0].push(cc[mp(0 , 0)]);
    cc.erase(mp(0 , 0));
    REP(i , 1 , n + 1) cin >> w[i];
    REP(i , 1 , n + 1){
        if(ma.find(w[i]) == ma.end() || ma[w[i]].size() == 0){
            cout << "NO" << endl;
            return 0;   
        }
        else {
            int tmp = ma[w[i]].front();
            ans.pb(ma[w[i]].front()) , ma[w[i]].pop();
            PII qq = x[tmp];
            if(cc.find(mp(qq.A + 1 , qq.B)) != cc.end()){
                ma[qq.B - (qq.A + 1)].push(cc[mp(qq.A + 1 , qq.B)]);
                cc.erase(mp(qq.A + 1 , qq.B));
            }
            if(cc.find(mp(qq.A , qq.B + 1)) != cc.end()){
                ma[qq.B + 1 - qq.A].push(cc[mp(qq.A , qq.B + 1)]);
                cc.erase(mp(qq.A , qq.B + 1));
            }
        }
    }
    cout << "YES" << endl;
    REP(i , 0 , ans.size()){
        cout << x[ans[i]].A << " " << x[ans[i]].B << endl;
    }
    return 0;
}