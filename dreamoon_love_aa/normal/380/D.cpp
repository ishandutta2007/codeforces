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
const int SIZE = 100010;
const int MOD = 1e9+7;
int pos[SIZE],a[SIZE];
long long fac[SIZE],inv[SIZE];
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}
void init(){
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
long long CC(int x,int y){
    if(y<0||y>x)return 0;
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
void err(){
    puts("0");
    exit(0);
}
int main(){
    init();
    DRI(n);
    int cnt=0,ma=0,ma_id;
    REP(i,n){
        RI(a[i]);
        if(a[i]){
            a[i]=n+1-a[i];
            cnt++;
            pos[a[i]]=i+1;
            if(a[i]>ma){
                ma=a[i];
                ma_id=a[i];
            }
        }
    }
    if(!cnt){
        int an=1;
        for(int i=1;i<n;i++){
            an=an*2%MOD;
        }
        printf("%d\n",an);
    }
    else{
        int lp=0,rp=0,last=0;
        long long now=1;
        REPP(i,1,ma_id){
            if(pos[i]){
                if(pos[i]<pos[ma_id]){
                    if(i-last>=pos[i]-lp){
                        now=now*CC(i-last-1,pos[i]-lp-1)%MOD;
                        rp+=(i-last)-(pos[i]-lp);
                        lp=pos[i];
                    }
                    else err();
                }
                else{
                    if(i-last>=(n+1)-pos[i]-rp){
                        now=now*CC(i-last-1,(n+1)-pos[i]-rp-1)%MOD;
                        lp+=(i-last)-((n+1)-pos[i]-rp);
                        rp=n+1-pos[i];
                    }
                    else err();
                }
                last=i;
            }
        }
        long long an=0;
        if(ma_id!=n){
            if(ma_id-last>=pos[ma_id]-lp){
                an+=now*CC(ma_id-last-1,pos[ma_id]-lp-1)%MOD;
            }
            if(ma_id-last>=(n+1)-pos[ma_id]-rp){
                an+=now*CC(ma_id-last-1,(n+1)-pos[ma_id]-rp-1)%MOD;
            }
            if(an>=MOD)an-=MOD;
            for(int i=ma_id+1;i<n;i++)an=an*2%MOD;
        }
        else{
            an=now*CC(n-1-last,pos[ma_id]-1-lp)%MOD;
        }
        cout<<an<<endl;
    }
    return 0;
}