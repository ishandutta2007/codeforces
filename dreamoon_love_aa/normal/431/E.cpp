#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
using namespace std;
map<int,long long>BIT1,BIT2;
const int INF = 1<<30;
void ins(map<int,long long>&BIT,int x,int v){
    x++;
    while(x<INF){
        BIT[x]+=v;
        x+=x&-x;
    }
}
int a[100010];
int main(){
    DRII(n,q);
    REP(i,n){
        RI(a[i]);
        ins(BIT1,a[i],1);
        ins(BIT2,a[i],a[i]);
    }
    while(q--){
        DRI(ty);
        if(ty==1){
            DRII(p,x);
            p--;
            ins(BIT1,a[p],-1);
            ins(BIT2,a[p],-a[p]);
            a[p]=x;
            ins(BIT1,a[p],1);
            ins(BIT2,a[p],a[p]);
        }
        else{
            long long v;
            scanf("%I64d",&v);
            int now=0;
            int num=0;
            long long sum=0;
            for(int i=29;i>=0;i--){
                int nxt=now+(1<<i);
                long long cover=(long long)(num+BIT1[nxt])*(nxt-1)-(sum+BIT2[nxt]);
                if(cover<v){
                    num+=BIT1[nxt];
                    sum+=BIT2[nxt];
                    now+=1<<i;
                }                
            }
            printf("%.12f\n",(sum+v)*1./num);
        }
    }
    return 0;
}