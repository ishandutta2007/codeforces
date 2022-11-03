#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <complex>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;


int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n; double p;
    scanf("%d",&n);
    double ex=0,add=0,one=0,last=0;
    for(int i=0;i<n;++i) {
        scanf("%lf",&p);
        ex+=(add+2*one)*p+p*(1-last);
        add=(add+2*one)*p+(1-last)*p; one=one*p+(1-last)*p;
        last=p;
    }
    printf("%.9lf\n",ex);
    return 0;
}