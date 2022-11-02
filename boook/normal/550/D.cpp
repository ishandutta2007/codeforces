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
#define MAX 
#define INF 0x3f3f3f3f

int n;
vector<PII> v;
void ADD(int a , int b){
    v.pb(mp(a * 2 + 1 , b * 2 + 1));
    v.pb(mp(a * 2 + 2 , b * 2 + 2));
}
int32_t main(){
    IOS;
    cin >> n;
    if(n == 1){
        cout << "YES" << endl;
        cout << "2 1" << endl;
        cout << "1 2" << endl;
    }
    else if(n % 2 == 0) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if(n == 3){

            REP(i , 1 , 7) ADD(i - 1 , i);
            v.pb(mp(1 , 2));
            ADD(0 , 6) , ADD(1 , 6);
            ADD(3 , 5) , ADD(2 , 4);
            cout << "14 21" << endl;
            for(auto to : v) cout << to.A << " " << to.B << endl;


            // sort(ALL(v));
            // v.resize(unique(ALL(v)) - v.begin());
            // assert(v.size() == 21);
            // vector<int> fk[100000];
            // for(auto to : v) fk[to.A].pb(to.B);
            // for(auto to : v) fk[to.B].pb(to.A);
            // REP(i , 1 , 14 + 1) assert(fk[i].size() == n);



        }
        else {
            int nn = (3 * (n - 2)) , cnt = nn * n;

            v.pb(mp(1 , 2));

            REP(i , 1 , nn) ADD(i - 1 , i);
            ADD(0 , nn - 1) , ADD((nn - 1) / 2 , nn - 1);

            for(int i = 1 ; i < (nn - 1) / 2 ; i ++)
                ADD(i , i + (nn - 1) / 2);

            REP(k , 0 , 3){
                REP(i , 0 , n - 2){
                    REP(j , i + 1 , n - 2){
                        ADD(i * 3 + k , j * 3 + k);
                    }
                }
            }


            // DB4("v.size() = " , v.size() , "cnt = " , cnt);
            cout << nn * 2 << " " << cnt << endl;
            for(auto to : v) cout << to.A << " " << to.B << endl;

        }
    }
    return 0;
}