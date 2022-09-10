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
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 3e5+10;
int from[SIZE],a[SIZE],b[SIZE];
int cnt[SIZE];
int an[SIZE];
struct data{
    int x,y,k,id;
    bool operator<(const data& b)const{
        return from[x]<from[b.x]||(from[x]==from[b.x]&&y<b.y);
    }
}qq[SIZE];
PII largest[4];
void check(PII x){
    int id=x.S;
    REP(i,4){
        if(x>largest[i]){
            REPP(j,i,4){
                PII tmp=largest[j];
                largest[j]=x;
                if(tmp.S==id)break;
                x=tmp;
            }
            break;
        }
    }
}
int main(){
    int N,Q;
    RII(N,Q);
    int sqN=sqrt(N+0.1);
    REP(i,N){
        RI(a[i]);
        from[i]=i/sqN;
    }
    REP(i,Q){
        RIII(qq[i].x,qq[i].y,qq[i].k);
        qq[i].x--;qq[i].y--;
        qq[i].id=i;
    }
    sort(qq,qq+Q);
    int lt=-1;
    REP(i,Q){
        int x=qq[i].x,y=qq[i].y;
        int ed=min(from[x]*sqN+sqN,y+1);
        if(from[x]!=lt){
            MS0(cnt);
            REP(j,4)largest[j]=MP(0,0);
            REPP(j,ed,y+1){
                cnt[a[j]]++;
                check(MP(cnt[a[j]],a[j]));
            }
            lt=from[x];
        }
        else REPP(j,max(qq[i-1].y+1,ed),y+1){
            cnt[a[j]]++;
            check(MP(cnt[a[j]],a[j]));
        }
        PII tmp_largest[4];
        memcpy(tmp_largest,largest,sizeof(largest));
        REPP(j,x,ed){
            cnt[a[j]]++;
            check(MP(cnt[a[j]],a[j]));
        }
        int res=-1;
        REP(j,4){
            if(largest[j].F*qq[i].k>y-x+1){
                if(res==-1||res>largest[j].S)res=largest[j].S;
            }
            else break;
        }
        REPP(j,x,ed)cnt[a[j]]--;
        an[qq[i].id]=res;
        memcpy(largest,tmp_largest,sizeof(largest));
    }
    REP(i,Q)printf("%d\n",an[i]);
    return 0;
}