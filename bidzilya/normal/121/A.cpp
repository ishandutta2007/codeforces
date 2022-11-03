#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iterator>
using namespace std;

const __int64 NMAX = 1e12;

int main(){
    __int64 q[100000];
    int pe=0,ps=0;

    q[0]=0;
    while (ps<=pe){
        if (q[ps]>=NMAX)
            break;
        q[++pe]=q[ps]*10+4;
        q[++pe]=q[ps]*10+7;
        ps++;
    }
    int l,r;
    cin >> l >> r;
    int ll;
    for (int i=1;i<=pe;i++)
        if (q[i]>=l){
            ll = i;
            break;
        }

    __int64 ans = 0;

    __int64 tec = l;
    while (tec<=r){
        __int64 newtec = q[ll];
        if (newtec>r)
            newtec = r;
        ans = ans + q[ll++]*(newtec-tec+1);

        tec = newtec+1;
    }
    cout << ans;
    return 0;
}