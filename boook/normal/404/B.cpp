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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

string tma , tmb;
int a , b , n;
int F(string s){
    s += ".";
    int ans = 0 , ok = -1;
    REP(i , s.size()){
        if(ok == -1){
            if(s[i] == '.') ok = 0;
            else if(s[i] >= '0' && s[i] <= '9') ans = ans * 10 + s[i] - '0';
        }
        else {
            if(s[i] >= '0' && s[i] <= '9') ans = ans * 10 + s[i] - '0' , ok ++;
        }
    }
    while(ok != 4) ans *= 10 , ok ++;
    return ans;
}
int32_t main(){
    cin >> tma >> tmb;
    cin >> n;
    a = F(tma) , b = F(tmb);
    b %= a * 4;
    int X[] = {1 , 0 , -1 , 0};
    int Y[] = {0 , 1 , 0 , -1};
    PII con[] = {mp(a , 0) , mp(a , a) , mp(0 , a) , mp(0 , 0)};
    PII now = mp(0 , 0);
    int dir = 0;

    REPNM(i , 1 , n + 1){
        int tmp = b;
        int dis = abs(now.A - con[dir].A) + abs(now.B - con[dir].B);
        while(tmp >= dis){
            // DBGG("dis = " , dis);
            // DBGG("tmp = " , tmp) ;
            // DBGG(now.A , now.B) ; 
            tmp -= dis;
            now = con[dir];
            dir = (dir + 1) % 4;
            dis = abs(now.A - con[dir].A) + abs(now.B - con[dir].B);
        }
        now.A += X[dir] * tmp;
        now.B += Y[dir] * tmp;
        double qq = now.A , ww = now.B;
        printf("%0.9lf %0.9lf\n", qq / 10000 , ww / 10000);
    }
    return 0;
}