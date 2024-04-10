#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>
#include<iomanip>

using namespace std;
typedef int var;

var A[4], B[4];



double Solve() {
    double a = A[0], b = A[1], c = A[2], d = A[3];
    double e = B[0], f = B[1], g = B[2], h = B[3];

    double C = a*d - b*c;
    double B = d*e + a*h - b*g - f*c;
    double A = h*e - f*g;


    if(C == 0) return 0;

    if(A == 0) {
        return -C / B;
    } else {
        double delta = B*B - 4*A*C;

        if(delta < 0)
            return 1e15;

        double r1 = (-B + sqrt(delta)) / 2/A;
        double r2 = (-B - sqrt(delta)) / 2/A;

        return min(fabs(r1), fabs(r2));

    }
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin>>A[0]>>A[1]>>A[2]>>A[3];

    double minx = 1e15;

    for(var conf = 0; conf < 16; conf ++) {
        for(var i=0; i<4; i++) {
            if(conf & (1 << i)) {
                B[i] = -1;
            } else {
                B[i] = 1;
            }
        }

        minx = min(minx, fabs(Solve()));

        //cerr<<fabs(Solve()) << ": " <<B[0]<<B[1]<<B[2]<<B[3]<<'\n';
    }

    cout<<fixed<<setprecision(12)<<minx;


    return 0;
}