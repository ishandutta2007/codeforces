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
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 5e5+5;
int a[SIZE];
int d[SIZE<<4];
int b[SIZE],bn;
void ins(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        d[id]=max(ll-1,d[id]);
        return;
    }
    int mm=(L+R)>>1;
    ins(L,mm,id*2,ll,rr);
    ins(mm+1,R,id*2+1,ll,rr);
}
int now=0;
int qq(int L,int R,int id,int pos){
    int mm=(L+R)>>1;
    if(d[id]>=now){
        return a[d[id]];
    }
    if(L==R)return -1;
    if(pos<=mm){
        return qq(L,mm,id*2,pos);
    }
    else{
        return qq(mm+1,R,id*2+1,pos);
    }
}
int lt[SIZE][3];
vector<int>an;
int main(){
    MS1(d);
    DRI(n);
    REP(i,n){
        RI(a[i]);
        b[bn++]=a[i];
    }
    sort(b,b+bn);
    bn=unique(b,b+bn)-b;
    REP(i,n)a[i]=lower_bound(b,b+bn,a[i])-b;
    MS1(lt);
    REP(i,n){
        if(lt[a[i]][2]>=now){
            REP(j,4)an.PB(a[i]);
            now=i+1;
            continue;
        }
        REP(j,2){
            if(lt[a[i]][j]>=now){
                int res=qq(0,n-1,1,lt[a[i]][j]);
                if(res!=-1){
                    an.PB(res);
                    an.PB(a[i]);
                    an.PB(res);
                    an.PB(a[i]);
                    now=i+1;
                    break;
                }
                else{
                    ins(0,n-1,1,lt[a[i]][j]+1,i-1);
                }
            }
        }
        for(int j=2;j>0;j--)lt[a[i]][j]=lt[a[i]][j-1];
        lt[a[i]][0]=i;
    }
    printf("%d\n",SZ(an));
    REP(i,SZ(an)){
        if(i)putchar(' ');
        printf("%d",b[an[i]]);
    }
    puts("");
    return 0;
}