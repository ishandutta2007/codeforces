#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

string a , b;
int c[MAX] , d[MAX];
long double v[MAX];
int32_t main(){
    cin >> a >> b;
    int po = 0;
    RREP(i , a.size() - 1 , 0){
        c[po ++] = a[i] - '0';
    }po = 0;
    RREP(i , b.size() - 1 , 0){
        d[po ++] = b[i] - '0';
    }

    RREP(i , MAX - 10 , 3){
        if(c[i] == d[i]) c[i] = d[i] = 0;
        else if(c[i] > d[i]){
            c[i] -= d[i] , d[i] = 0;
            if(c[i] > 3) return cout << ">" << endl , 0;
            else c[i - 1] += c[i] , c[i - 2] += c[i] , c[i] = 0;
        }
        else {
            d[i] -= c[i] , c[i] = 0;
            if(d[i] > 3) return cout << "<" << endl , 0;
            else d[i - 1] += d[i] , d[i - 2] += d[i] , d[i] = 0;
        }
    }
    v[0] = 1;
    long double x = (sqrt(5.0) + 1.0) / 2.0;
    REP(i , 1 , 4) v[i] = v[i - 1] * x;
    long double q = 0 , w = 0;
    REP(i , 0 , 4){
        q += v[i] * c[i];
        w += v[i] * d[i];
    }
    // cout << q << " " << w << endl;
    if(fabs(q - w) < 1e-9) cout << "=" << endl;
    else if(q > w) cout << ">" << endl;
    else if(q < w) cout << "<" << endl;
    return 0;
}