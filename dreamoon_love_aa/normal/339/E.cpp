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
#define SIZE 1024
int a[SIZE],n;
int an[3][2];
bool check(){
    for(int i=1;i<=n;i++)
        if(a[i]!=i)return 0;
    return 1;
}
vector<pair<int,int> >pp;
void dfs(int lv){
    if(check()){
        printf("%d\n",lv);
        REP(i,lv)printf("%d %d\n",an[lv-1-i][0],an[lv-1-i][1]);
        exit(0);
    }
    if(lv==3)return;
    vector<pair<int,int> >tmp=pp;
    for(int i=0;i<SZ(pp);i++){
        for(int j=i;j<SZ(pp);j++){
            if(pp[i].F==pp[j].S)continue;
            reverse(a+pp[i].F,a+pp[j].S+1);
            int now=0;
            for(int k=0;i+k<j;k++){
                now+=tmp[j-k].S-tmp[j-k].F+1;
                pp[i+k].S=pp[i].F+now-1;
                pp[i+k+1].F=pp[i].F+now;
            }
            an[lv][0]=pp[i].F;
            an[lv][1]=pp[j].S;
            dfs(lv+1);
            for(int k=0;i+k<=j;k++){
                pp[i+k]=tmp[i+k];
            }
            reverse(a+pp[i].F,a+pp[j].S+1);
        }
    }
}
int main(){
    int i,j,k;
    scanf("%d",&n);
    a[n+1]=n+1;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int last=1,st=1;
    for(i=1;i<n;i++){
        if((!st&&a[i]-a[i-1]!=a[i+1]-a[i])||abs(a[i]-a[i+1])!=1){
            if(last!=i){
                pp.PB(MP(last,last));
                pp.PB(MP(last+1,i));
            }
            else pp.PB(MP(last,i));
            last=i+1;
            st=1;
        }
        else st=0;
    }
    if(last!=n+1)pp.PB(MP(last,n));
    dfs(0);
    return 0;
}