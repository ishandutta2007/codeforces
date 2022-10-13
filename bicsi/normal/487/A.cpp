#include <bits/stdc++.h>

using namespace std;
typedef int var;


var ma, md, mh, ya, yd, yh, a, d, h;
var yai, ydi, yhi;

#define FOR(i,a) for(i=a;i<=200;i++)


bool good(var yh) {
    if(ya <= md) return false;
    if(ma <= yd) return true;

    var yhh = yh, mhh = mh;

    while(yhh > 0 && mhh > 0) {
        yhh -= ma - yd;
        mhh -= ya - md;
    }

    return yhh > 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    cin>>yhi>>yai>>ydi;
    cin>>mh>>ma>>md;
    cin>>h>>a>>d;

    var best = 2000000000;
    FOR(ya, yai) FOR(yd, ydi) {

        yh = yhi - 1;
        for(var i=(1<<15); i; i>>=1)
            if(!good(yh+i))
                yh+=i;
        yh ++;
        best = min(best, h*(yh - yhi) + d*(yd - ydi) + a*(ya - yai));
    }
    cout<<best;

    return 0;
}