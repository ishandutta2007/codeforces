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
using namespace std;
#define SIZE 100010
struct data{
    int x,y;
    data(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator<(const data& b)const{
        if(x==b.x){
            if(abs(y)==abs(b.y))return y<b.y;
            return abs(y)<abs(b.y);
        }
        if(abs(x)==abs(b.x)){
            return x<b.x;
        }
        return abs(x)<abs(b.x);
    }
}a[100000];
int main(){
    int step=0;
    DRI(n);
    REP(i,n){
        RII(a[i].x,a[i].y);
        if(a[i].x==0||a[i].y==0)step+=4;
        else step+=6;
    }
    sort(a,a+n);
    printf("%d\n",step);
    REP(i,n){
        if(a[i].x==0){
            if(a[i].y>0){
                printf("1 %d U\n2\n1 %d D\n3\n",a[i].y,a[i].y);
            }
            else{
                printf("1 %d D\n2\n1 %d U\n3\n",-a[i].y,-a[i].y);
            }
        }
        else if(a[i].y==0){
            if(a[i].x>0){
                printf("1 %d R\n2\n1 %d L\n3\n",a[i].x,a[i].x);
            }
            else{
                printf("1 %d L\n2\n1 %d R\n3\n",-a[i].x,-a[i].x);
            }
        }
        else{
            if(a[i].x>0){
                printf("1 %d R\n",a[i].x);
            }
            else{
                printf("1 %d L\n",-a[i].x);
            }
            if(a[i].y>0){
                printf("1 %d U\n2\n",a[i].y);
            }
            else{
                printf("1 %d D\n2\n",-a[i].y);
            }

            if(a[i].y>0){
                printf("1 %d D\n",a[i].y);
            }
            else{
                printf("1 %d U\n",-a[i].y);
            }
            if(a[i].x>0){
                printf("1 %d L\n3\n",a[i].x);
            }
            else{
                printf("1 %d R\n3\n",-a[i].x);
            }
        }
    }
    return 0;
}