#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
const double EPS=1e-12;
using namespace std;
double XX(int x1,int y1,int x2,int y2){
    if(x1==x2)return 0;
    if(y1==y2)return 1;
    if(x1<=x2&&y1<=y2)return -1;
    if(x1>=x2&&y1>=y2)return -1;
    int d1=abs(x1-x2);
    int d2=abs(y1-y2);
    return d1*1./(d1+d2);
}
double get_h(int x,int y,double v){
    return x+(y-x)*v;
}
int a[300][301];
double b[300][300][2];
int main(){
    DRII(n,k);
    REP(i,k+1)RI(a[0][i]);
    {
        double an=0;
        REP(i,k){
            an+=(a[0][i]+a[0][i+1])*0.5;
            b[0][i][0]=0;
            b[0][i][1]=1;
        }
        printf("%.9f\n",an);
    }
    REPP(i,1,n){
        REP(j,k+1)RI(a[i][j]);
        double an=0;
        REP(j,k){
            b[i][j][0]=1;
            b[i][j][1]=0;
            REP(r,i){
                if(b[r][j][0]<-0.5)continue;
                double lx=b[r][j][0];
                double rx=b[r][j][1];
                if(a[r][j]<=a[i][j]&&a[r][j+1]<=a[i][j+1]){
                    an+=(get_h(a[i][j],a[i][j+1],lx)+get_h(a[i][j],a[i][j+1],rx))*(rx-lx);
                    an-=(get_h(a[r][j],a[r][j+1],lx)+get_h(a[r][j],a[r][j+1],rx))*(rx-lx);
                    b[i][j][0]=min(b[i][j][0],lx);
                    b[i][j][1]=max(b[i][j][1],rx);
                    b[r][j][0]=b[r][j][1]=-1;
                }
                else if(a[r][j]>=a[i][j]&&a[r][j+1]>=a[i][j+1])break;
                else{
                    double mm=XX(a[r][j],a[r][j+1],a[i][j],a[i][j+1]);
                    if(a[r][j]<=a[i][j]){
                        if(lx+EPS<=mm){
                            if(rx<=mm+EPS){
                                an+=(get_h(a[i][j],a[i][j+1],lx)+get_h(a[i][j],a[i][j+1],rx))*(rx-lx);
                                an-=(get_h(a[r][j],a[r][j+1],lx)+get_h(a[r][j],a[r][j+1],rx))*(rx-lx);
                                b[r][j][0]=b[r][j][1]=-1;
                                b[i][j][0]=min(b[i][j][0],lx);
                                b[i][j][1]=max(b[i][j][1],rx);
                            }
                            else{
                                an+=(get_h(a[i][j],a[i][j+1],lx)+get_h(a[i][j],a[i][j+1],mm))*(mm-lx);
                                an-=(get_h(a[r][j],a[r][j+1],lx)+get_h(a[r][j],a[r][j+1],mm))*(mm-lx);
                                b[r][j][0]=mm;
                                b[i][j][0]=min(b[i][j][0],lx);
                                b[i][j][1]=max(b[i][j][1],mm);
                            }
                        }
                    }
                    else{
                        if(rx>=mm+EPS){
                            if(lx+EPS>=mm){
                                an+=(get_h(a[i][j],a[i][j+1],lx)+get_h(a[i][j],a[i][j+1],rx))*(rx-lx);
                                an-=(get_h(a[r][j],a[r][j+1],lx)+get_h(a[r][j],a[r][j+1],rx))*(rx-lx);
                                b[r][j][0]=b[r][j][1]=-1;
                                b[i][j][0]=min(b[i][j][0],lx);
                                b[i][j][1]=max(b[i][j][1],rx);
                            }
                            else{
                                an+=(get_h(a[i][j],a[i][j+1],mm)+get_h(a[i][j],a[i][j+1],rx))*(rx-mm);
                                an-=(get_h(a[r][j],a[r][j+1],mm)+get_h(a[r][j],a[r][j+1],rx))*(rx-mm);
                                b[r][j][1]=mm;
                                b[i][j][0]=min(b[i][j][0],mm);
                                b[i][j][1]=max(b[i][j][1],rx);
                            }
                        }
                    }
                }
            }
            if(b[i][j][1]<b[i][j][0]+EPS)b[i][j][0]=b[i][j][1]=-1;
        }
        printf("%.9f\n",an*0.5);
    }
    return 0;
}