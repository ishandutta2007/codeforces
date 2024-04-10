#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
//#include <ctime>
//#include <cmath>
#include <memory.h>
#include <string>
#include <set>

using namespace std;

double x0=13.0901699437495,y0=9.5105651629515;
double x1=5.0000000000000,y1=15.3884176858763;
double x2=-3.0901699437495,y2=9.5105651629515;
double x3=0.0000000000000,y3=0.0000000000000;
double x4=10.0000000000000,y4=0.0000000000000;


double x5=13.0901699437495,y5=-9.5105651629515;
double x6=5.0000000000000,y6=-15.3884176858763;
double x7=-3.0901699437495,y7=-9.5105651629515;
double x8=0.0000000000000,y8=0.0000000000000;
double x9=10.0000000000000,y9=0.0000000000000;


int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
/*  double Pi=3.14159265358979323846264,R=5.0/sin(Pi/5);
    cout << R << endl;
    cout.precision(15);
    double fi=Pi/10;
    for(int i=0;i<5;++i) {
//      cout << R*cos(fi+2*Pi*i/5)+5 << "," << R*sin(fi+2*Pi*i/5)+6.88190960235587 << endl;
        printf("double x%d=%.13lf,y%d=%.13lf;\n",i+5,R*cos(fi+2*Pi*i/5)+5,i+5,-R*sin(fi+2*Pi*i/5)-6.88190960235587);
    }*/
    int n;
    scanf("%d",&n);
    printf("%d\n",5+4*(n-1));
    printf("%.12lf %.12lf\n",x0,y0);
    printf("%.12lf %.12lf\n",x1,y1);
    printf("%.12lf %.12lf\n",x2,y2);
    printf("%.12lf %.12lf\n",x3,y3);
    printf("%.12lf %.12lf\n",x4,y4);
    for(int i=1;i<n;++i) {
        double add=i*10;
        if (i%2==0) {
            printf("%.12lf %.12lf\n",x0+add,y0);
            printf("%.12lf %.12lf\n",x1+add,y1);
            printf("%.12lf %.12lf\n",x2+add,y2);
            printf("%.12lf %.12lf\n",x4+add,y4);
        } else {
            printf("%.12lf %.12lf\n",x5+add,y5);
            printf("%.12lf %.12lf\n",x6+add,y6);
            printf("%.12lf %.12lf\n",x7+add,y7);
            printf("%.12lf %.12lf\n",x9+add,y9);
        }
    }
    printf("%d %d %d %d %d\n",1,2,3,4,5);
    for(int i=1;i<n;++i) {
        if (i&1) {
            printf("%d %d %d %d %d\n",4*i+1,4*i+3+1,4*i+2+1,4*i+1+1,4*i+4+1);
        } else {
            printf("%d %d %d %d %d\n",4*i+1,4*i+3+1,4*i+2+1,4*i+1+1,4*i+4+1);
        }
    }
    printf("%d %d %d",4,2,5);
    for(int i=1;i<n;++i) {
        if (i&1) printf(" %d %d",4*i+2+1,4*i+4+1);
        else printf(" %d %d",4*i+2+1,4*i+4+1);
    }
    for(int i=n-1;i>=1;--i) {
        if (i&1) {
            printf(" %d %d %d",4*i+3+1,4*i+1+1,4*i+1);
        } else {
            printf(" %d %d %d",4*i+3+1,4*i+1+1,4*i+1);
        }
    }
    printf(" %d %d %d\n",3,1,4);
    return 0;
}