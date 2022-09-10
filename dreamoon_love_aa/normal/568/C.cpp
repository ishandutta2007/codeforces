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
const int SIZE = 410;
// template end here
struct SCC{
    int n,used[SIZE],order[SIZE],gg[SIZE];
    vector<int>e[SIZE],ae[SIZE],ge[SIZE],emp;
    int id,gn;
    void init(int _n){
        n=_n;
        memset(used,0,sizeof(int)*n);
        REP(i,n){
            e[i]=ae[i]=ge[i]=emp;
        }
    }
    void add_edge(int x,int y){
        e[x].PB(y);
        ae[y].PB(x);
    }
    void pop(int x){
        e[x].pop_back();
        ae[x^1].pop_back();
    }
    void dfs1(int x){
        if(used[x]==1)return;
        used[x]=1;
        REP(i,SZ(e[x])){
            int y=e[x][i];
            dfs1(y);
        }
        order[--id]=x;
    }
    void dfs2(int x){
        if(used[x]==2)return;
        gg[x]=gn;
        used[x]=2;
        REP(i,SZ(ae[x])){
            int y=ae[x][i];
            if(used[y]==2){
                //if(gg[y]!=gg[x])ge[gg[y]].PB(gg[x]);
            }
            else dfs2(y);
        }
    }
    bool make_scc(){
        memset(used,0,sizeof(int)*n);
        gn=0;
        id=n;
        REP(i,n)
            dfs1(i);
        REP(i,n){
            if(used[order[i]]!=2){
                dfs2(order[i]);
                gn++;
            }
        }
        REP(i,n){
            if(gg[i]==gg[i+1])return 0;
            i++;
        }
        return 1;
        /*REP(i,gn){
            sort(ALL(ge[i]));
            ge[i].resize(unique(ALL(ge[i]))-ge[i].begin());
        }*/
    }
}scc;
char letters[30];
char input[210],s[210];
int ty(char c){
    if(c=='V')return 1;
    return 0;
}
bool check(int n){
    bool res;
    REP(i,n){
        if(s[i]){
            scc.add_edge(i*2+1-ty(letters[s[i]-'a']),i*2+ty(letters[s[i]-'a']));
        }
    }
    res=scc.make_scc();
    REP(i,n){
        if(s[i])scc.pop(i*2+1-ty(letters[s[i]-'a']));
    }
    return res;
}
int main(){
    RS(letters);
    int sz=LEN(letters);
    DRII(n,m);
    scc.init(2*n);
    REP(i,m){
        int x,y;
        char s1[14],s2[14];
        scanf("%d%s%d%s",&x,s1,&y,s2);
        x--;y--;
        scc.add_edge(x*2+ty(s1[0]),y*2+ty(s2[0]));
        scc.add_edge(y*2+1-ty(s2[0]),x*2+1-ty(s1[0]));
    }
    RS(input);
    strcpy(s,input);
    if(check(n))puts(input);
    else{
        bool err=1;
        REPP(i,1,sz){
            if(letters[i]!=letters[0])err=0;
        }
        if(err){
            puts("-1");
            return 0;
        }
        for(int i=n-1;i>=0;i--){
            set<char>c_used;
            for(int j=input[i]+1;j<'a'+sz;j++){
                if(!c_used.count(letters[j-'a'])){
                    strcpy(s,input);
                    c_used.insert(letters[j-'a']);
                    s[i]=j;
                    REPP(k,i+1,n)s[k]=0;
                    if(check(n)){
                        REPP(k,i+1,n){
                            set<char>c_used2;
                            REP(cc,sz){
                                if(!c_used2.count(letters[cc])){
                                    s[k]=cc+'a';
                                    if(SZ(c_used2))break;
                                    c_used2.insert(letters[cc]);
                                    if(check(n))break;
                                }
                            }
                        }
                        puts(s);
                        return 0;
                    }
                }
            }
        }
        puts("-1");
    }
    return 0;
}