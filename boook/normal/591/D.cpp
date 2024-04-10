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
#define PII pair<double , double>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

PII from , to , a , b;
double mv , t;
int judge(double now){
    PII tmp = from;
    if(now >= t){
        tmp.A += t * a.A;
        tmp.B += t * a.B;
        tmp.A += (now - t) * b.A;
        tmp.B += (now - t) * b.B;
        double dis = (to.A - tmp.A) * (to.A - tmp.A) + (to.B - tmp.B) * (to.B - tmp.B);
        dis = sqrt(dis);
        if(mv * now >= dis) return 1;
        else return 0;
    }
    else{
        tmp.A += now * a.A;
        tmp.B += now * a.B;
        double dis = (to.A - tmp.A) * (to.A - tmp.A) + (to.B - tmp.B) * (to.B - tmp.B);
        dis = sqrt(dis);
        if(mv * now >= dis) return 1;
        else return 0;
    } 
}
int32_t main(){
    cin >> from.A >> from.B >> to.A >> to.B;
    cin >> mv >> t;
    cin >> a.A >> a.B;
    cin >> b.A >> b.B;
    double l = 0 , r = 100000000;
    int ttt = 100;
    while(ttt--){
        double mid = (l + r) / 2;
        if(judge(mid)) r = mid;
        else l = mid;
    }
    printf("%.017f\n", l);
    return 0;
}