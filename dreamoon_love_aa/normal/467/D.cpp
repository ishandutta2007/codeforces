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
char s[SIZE],s2[SIZE];
map<string,int>H;
pair<int,int>mi[SIZE];
int id=0;
bool big(char c){
    return c>='A'&&c<='Z';
}
int add(char ss[]){
    int len=0;
    int r=0;
    for(;ss[len];len++){
        if(big(ss[len]))ss[len]-='A'-'a';
        if(ss[len]=='r')r++;
    }
    if(!H.count(ss)){
        mi[id]=MP(r,len);
        return H[ss]=id++;
    }
    else return H[ss];
}
vector<int>e[SIZE];
int cnt[SIZE];
struct data{
    int x;
    pair<int,int>pp;
    data(int _x,pair<int,int>_pp):x(_x),pp(_pp){}
    bool operator<(const data& b)const{return b.pp<pp;}
};
priority_queue<data>heap;
int main(){
    DRI(n);
    REP(i,n){
        RS(s);
        int x=add(s);
        cnt[x]++;
    }
    DRI(m);
    REP(i,m){
        RS(s);
        RS(s2);
        int x=add(s);
        int y=add(s2);
        e[y].PB(x);
    }
    REP(i,id){
        heap.push(data(i,mi[i]));
    }
    while(!heap.empty()){
        data now=heap.top();heap.pop();
        if(mi[now.x]<now.pp)continue;
        REP(i,SZ(e[now.x])){
            int y=e[now.x][i];
            if(now.pp<mi[y]){
                mi[y]=now.pp;
                heap.push(data(y,mi[y]));
            }
        }
    }
    LL an=0,an2=0;
    REP(i,id){
        an+=(LL)cnt[i]*mi[i].S;
        an2+=(LL)cnt[i]*mi[i].F;
    }
    cout<<an2<<" "<<an<<endl;
    return 0;
}