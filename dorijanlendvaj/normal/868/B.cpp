#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-4;

int h,m,s,t1,t2,g1,g2;
double x1,x2,x3;
double yy1,y2,c1,c2;

int main(){
    scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
    x1 = (double)h + (double)m / 60.0 +  (double)s / 3600.0;
    x2 = (double)m / 5.0 + (double)s / 360.0;
    x3 = (double)s / 5.0;
    if(x1 > 12.0) x1 -= 12.0;
    if(x2 > 12.0) x2 -= 12.0;
    if(x3 > 12.0) x3 -= 12.0;
    yy1 = (double)t1;
    y2 =  (double)t2;
    c1 = yy1;
    c2 = y2;
    while(abs(c1 - c2) >= EPS){
        if(abs(c1 - x1) <= EPS  || abs(c1 - x2) <= EPS|| abs(c1 - x3) <= EPS) {g1 = 1;break;}
        if(abs(c1 - 12.0) <= EPS) c1 = 0.0;
        c1 += EPS;
    }
    c1 = yy1;
    c2 = y2;
    while(abs(c1 - c2) >= EPS){
        //cout << c1 << " " << c2 << endl;

        if(abs(c1 - x1) <= EPS  || abs(c1 - x2) <= EPS|| abs(c1 - x3) <= EPS) {g2 = 1;break;}
        c1 -= EPS;
        if(c1 <= 0.0) c1 += 12.0;
    }
    if(!g1 || !g2){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}