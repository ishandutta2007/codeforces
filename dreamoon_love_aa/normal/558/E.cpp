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
const int SIZE = 1e6+10;
struct data{
    int id,num,c;
    data(int _id=0,int _num=0,int _c=0):id(_id),num(_num),c(_c){}
    bool operator<(const data& b)const{return id<b.id;}
};
set<data>H;
char s[SIZE];
int inter(int x1,int y1,int x2,int y2){
    return max(0,min(y1,y2)-max(x1,x2)+1);
}
int main(){
    DRII(n,q);
    RS(s);
    for(int i=0,j;i<n;i=j){
        for(j=i;j<n&&s[j]==s[i];j++);
        H.insert(data(i+1,j-i,s[i]-'a'));
    }
    while(q--){
        DRIII(i,j,k);
        set<data>::iterator st=H.upper_bound(data(i));
        st--;
        set<data>::iterator ed=st;
        int cnt[26]={};
        vector<data>add;
        for(;ed!=H.end()&&ed->id<=j;ed++){
            cnt[ed->c]+=inter(i,j,ed->id,ed->id+ed->num-1);
            if(ed->id+ed->num-1>j)
                add.PB(data(j+1,ed->num-(j-ed->id+1),ed->c));
        }
        if(st->id<i){
            add.PB(data(st->id,i-st->id,st->c));
        }
        H.erase(st,ed);
        REP(i,SZ(add))H.insert(add[i]);
        int now=i;
        if(k){
            REP(i,26){
                if(cnt[i])H.insert(data(now,cnt[i],i));
                now+=cnt[i];
            }
        }
        else{
            for(int i=25;i>=0;i--){
                if(cnt[i])H.insert(data(now,cnt[i],i));
                now+=cnt[i];
            }
        }
    }
    for(set<data>::iterator it=H.begin();it!=H.end();it++){
        REP(i,(it->num))putchar(it->c+'a');
    }
    puts("");
    return 0;
}