/*input
4
3 5 3
..R..
...R.
....R
6 4 6
R..R
R..R
RRRR
RRRR
R..R
R..R
5 5 4
RRR..
R.R..
RRR..
R..R.
R...R
2 31 62
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 110
#define INF 0x3f3f3f3f

struct djs{
    int x[MAX * MAX];
    void init(){ REP(i , 0 , MAX * MAX) x[i] = i; }
    int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int a){ return Find(a); }
} ds;

vector<char> v;
string s[MAX];
int t , n , m , k, idx[MAX][MAX] , ans[MAX][MAX] , idxpo = 0;
int32_t main(){
    IOS;
    REP(i , 0 , 26) v.pb('a' + i);
    REP(i , 0 , 26) v.pb('A' + i);
    REP(i , 0 , 10) v.pb('0' + i);

    cin >> t; 
    REP(times , 0 , t){
        cin >> n >> m >> k;
        REP(i , 0 , n) cin >> s[i];
        int cnt = 0;
        REP(i , 0 , n) REP(j , 0 , m) cnt += s[i][j] == 'R';
        ds.init(), idxpo = 0;
        REP(i , 0 , n) REP(j , 0 , m) idx[i][j] = idxpo ++;

        vector<int> have;

        REP(i , 0 , k) have.pb(cnt / k);
        cnt -= cnt / k * k;
        REP(i , 0 , have.size()) if(cnt) cnt --, have[i] ++;

        // for(auto to : have) cout << to << " "; cout << endl;
        
        int pos = 0, nowhave = 0;
        REP(i , 0 , n){
            if(i % 2 == 0){
                REP(j , 0 , m){
                    if(nowhave + (s[i][j] == 'R') > have[pos]){
                        pos ++, nowhave = 0;
                    }
                    nowhave += s[i][j] == 'R';
                    ans[i][j] = pos;
                }
            }
            else {
                RREP(j , m - 1 , 0){
                    if(nowhave + (s[i][j] == 'R') > have[pos]){
                        pos ++, nowhave = 0;
                    }
                    nowhave += s[i][j] == 'R';
                    ans[i][j] = pos;
                }
            }
        }
        REP(i , 0 , n){
            REP(j , 0 , m){
                cout << v[ans[i][j]];
            }cout << endl;
        }
    }
    return 0;
}