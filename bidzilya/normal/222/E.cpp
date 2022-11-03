#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = 1e9;
const ll MAX_LL = 1e18;
const double eps = 1e-8;

class matr{
      ll x[52][52];
public:
       ll & at(int i,int j){return x[i][j];}
       matr(){};
};

matr ed,a;
ll n;
int k,m;

matr & proizv(matr & x, matr & y){
     matr res;
     for (int i=0;i<m;i++)
         for (int j=0;j<m;j++){
             res.at(i,j)=0;
             for (int i1=0;i1<m;i1++)
                 res.at(i,j)=(res.at(i,j)+x.at(i,i1)*y.at(i1,j))%MD;
         }
     return res;
}

matr & pow(ll x){
     if (x==1)return ed;
     matr tmp;
     if (x%2==0){
        tmp = pow(x/2);
        return proizv(tmp,tmp);
     }
     tmp = pow(x-1);
     return proizv(tmp,ed);
}

int main(){
    cin >> n >> m >> k;
    if (n==1){
       cout << m << endl;
       //system("pause");
       return 0;
    }
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            ed.at(i,j)=1;
    for (int i=0;i<k;i++){
        char c1,c2;
        cin >> c1 >> c2;
        int i1,i2;
        if (c1>='a' && c1<='z')i1=c1-'a';else i1=c1-'A'+26;
        if (c2>='a' && c2<='z')i2=c2-'a';else i2=c2-'A'+26;
        ed.at(i2,i1)=0;
    }
    a = pow(n-1);
    ll res = 0;
    for (int i=0;i<m;i++)                     
        for (int j=0;j<m;j++)
            res = (res+a.at(i,j))%MD;
    cout << res << endl;
    //system("pause");
    return 0;
}