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

string s;
int k;
int32_t main(){
    cin >> s >> k;
    int siz = s.size();
    if(siz % k == 0) siz /= k;
    else {
        cout << "NO" << endl;
        return 0;
    }
    int now = 0;
    while(now < s.size()){
        string tmp = s.substr(now , siz);
        string b = tmp;
        reverse(ALL(b));
        if(tmp != b){
            cout << "NO" << endl;
            return 0;
        }
        now += siz;
    }
    cout << "YES" << endl;
    return 0;
}