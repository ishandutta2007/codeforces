#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    __int64 h,w,th,tw,aw,ah=-1,bw,bh;
    cin >> h >> w;
    for (tw=1;tw<=w;tw*=2){
        th = 5*tw;
        bh = 4*tw;
        while (th%4!=0)
            th--;
        th /=4;
        while (bh%5!=0)
            bh++;
        bh /=5;
        if (th>h)
            th = h;
        if (th<bh)
            continue;
        if (ah==-1 || (ah*aw<th*tw) || (ah*aw==th*tw && th>ah)){
            ah = th;
            aw = tw;
        }
    }
    for (th=1;th<=h;th*=2){
        tw = 5*th;
        bw = 4*th;
        while (tw%4!=0)
            tw--;
        tw /=4;
        while (bw%5!=0)
            bw++;
        bw /=5;
        if (tw>w)
            tw = w;
        if (tw<bw)
            continue;
        if (ah==-1 || (ah*aw<th*tw) || (ah*aw==th*tw && th>ah)){
            ah = th;
            aw = tw;
        }
    }
    cout << ah << ' ' << aw;
    return 0;
}