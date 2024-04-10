#include <bits/stdc++.h>
using namespace std;

long long n,lastyear,q;

inline void getnext(){
    if (lastyear%400==0 || (lastyear%4==0 && lastyear%100!=0)) q+=366;
    else q+=365;
    ++lastyear;
}
inline bool chek(){
    if (q%7!=0) return false;
    bool t=false,tt=false;
    if (n%4==0 && n%100!=0) t=true;
    if (n%400==0) t=true;
    if (lastyear%4==0 && lastyear%100!=0) tt=true;
    if (lastyear%400==0) tt=true;
    return t==tt;
}
int main(){
    cin>>n;
    lastyear=n;
    getnext();
    while (true) {
        if (chek()) {
            cout<<lastyear<<'\n';
                return 0;
            }
            getnext();
    }
}