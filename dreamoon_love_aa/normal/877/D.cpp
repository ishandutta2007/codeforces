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
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define F first
#define S second
typedef int64_t LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e3+10;
char s[SIZE][SIZE];
set<int>row[SIZE],col[SIZE];
PII bfs[SIZE*SIZE];
bool visited[SIZE][SIZE];
int dis[SIZE][SIZE];
int main(){
    MS1(dis);
    DRIII(n,m,k);
    REP(i,n){
        RS(s[i]);
        REP(j,m){
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    DRII(sx,sy);sx--;sy--;
    DRII(ex,ey);ex--;ey--;
    bfs[0]=MP(sx,sy);
    dis[sx][sy]=0;
    int rrr=1;
    visited[sx][sy]=1;
    REP(i,rrr){
        PII me=bfs[i];
//        printf("%d %d:%d\n",me.F,me.S,dis[me.F][me.S]);
        int ll=bfs[i].S-k;
        int rr=bfs[i].S+k;
        auto it=row[me.F].lower_bound(bfs[i].S);
        auto it2=it;
        while(it!=row[me.F].end()&&*it<=rr&&s[me.F][*it]!='#'){
            if(!visited[me.F][*it]){
//                printf("1[%d,%d,%d,%d]\n",me.F,me.S,ll,*it);
                visited[me.F][*it]=1;
                bfs[rrr++]=MP(me.F,*it);
                dis[me.F][*it]=dis[me.F][me.S]+1;
            }
            it++;
        }
        row[me.F].erase(it2,it);
        it2=it=row[me.F].lower_bound(bfs[i].S);
        if(it!=row[me.F].begin()){
            it--;
            while(*it>=ll&&s[me.F][*it]!='#'){
                if(!visited[me.F][*it]){
//                    printf("2[%d,%d,%d,%d]\n",me.F,me.S,ll,*it);
                    visited[me.F][*it]=1;
                    bfs[rrr++]=MP(me.F,*it);
                    dis[me.F][*it]=dis[me.F][me.S]+1;
                }
                if(it==row[me.F].begin())
                    break;
                it--;
            }
            if(*it<ll||s[me.F][*it]=='#')it++;
            row[me.F].erase(it,it2);
        }

        ll=bfs[i].F-k;
        rr=bfs[i].F+k;
        it2=it=col[me.S].lower_bound(bfs[i].F);
        while(it!=col[me.S].end()&&*it<=rr&&s[*it][me.S]!='#'){
//            printf("3[%d,%d,%d,%d]\n",me.F,me.S,ll,*it);
            if(!visited[*it][me.S]){
                visited[*it][me.S]=1;
                bfs[rrr++]=MP(*it,me.S);
                dis[*it][me.S]=dis[me.F][me.S]+1;
            }
            it++;
        }
        col[me.S].erase(it2,it);
        it2=it=col[me.S].lower_bound(bfs[i].F);
        if(it!=col[me.S].begin()){
            it--;
            while(*it>=ll&&s[*it][me.S]!='#'){
//            printf("4[%d,%d,%d,%d]\n",me.F,me.S,ll,*it);
                if(!visited[*it][me.S]){
                    visited[*it][me.S]=1;
                    bfs[rrr++]=MP(*it,me.S);
                    dis[*it][me.S]=dis[me.F][me.S]+1;
                }
                if(it==col[me.S].begin())
                    break;
                it--;
            }
            if(*it<ll||s[*it][me.S]=='#')it++;
            col[me.S].erase(it,it2);
        }
    }
    printf("%d\n",dis[ex][ey]);
    return 0;
}