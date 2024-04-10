#include <complex>
#include <cstdio>
using namespace std;

#define EPS 1e-7

typedef complex<double> point;

int contact(point p1, double r1, point p2, double r2){
    double d = abs(p2 - p1);

    if( r1 + r2 < d + EPS ) return 0;
    if( d + r2 < r1 + EPS ) return -1;
    if( d + r1 < r2 + EPS ) return -2;
    return 1;
}

int main(){
    double x, y;
    point p[2];
    double r[2], R[2];
    
    for(int i = 0; i < 2; ++i){
        scanf("%lf%lf%lf%lf", &x, &y, &r[i], &R[i]);
        p[i] = point(x, y);
    }
    
    int c = 0;
    for(int i = 0; i < 2; ++i){
        int j = 1 - i;
        double *rr = r;

        for(int k = 0; k < 2; ++k){
            int a = contact(p[i], rr[i], p[j], r[j]);
            int b = contact(p[i], rr[i], p[j], R[j]);

            if( a != 1 && b != 1 ){
                if( a == -2 || b != -2 ){
                    ++c;
                }
            }
            
            rr = R;
        }
    }
    
    printf("%d\n", c);
}