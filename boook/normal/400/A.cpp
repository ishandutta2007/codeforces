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
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string s;
int n;
int32_t main(){
    cin >> n;
    REP(times , n){
        VI ans;
        cin >> s;
        for(auto i : {12 , 6 , 4 , 3 , 2 , 1}){
            int use[1000];
            MEM(use , 0);
            REP(j , s.size()){
                if(s[j] == 'O') use[j % i] = -1;
            }
            REP(j , i){
                if(use[j] != -1){
                    ans.pb(i);
                    break;
                }
            }
        }
        cout << ans.size() << " ";
        REP(j , ans.size()) printf("%dx%d ", 12 / ans[j] , ans[j]);
        puts("");
    }

    return 0;
}