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
const int SIZE = 4900;
int in[SIZE],out[SIZE];
vector<int>e[SIZE];
int it[SIZE];
int get(char c){
    if(c>='a'&&c<='z')return c-'a';
    if(c>='A'&&c<='Z')return c-'A'+26;
    return c-'0'+52;
}
char to(int x){
    if(x<26)return 'a'+x;
    if(x<52)return 'A'+x-26;
    return x-52+'0';
}
struct Union_Find{
    int d[SIZE];
    void init(int n){
        REP(i,n)d[i]=i;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        d[x]=y;
        return 1;
    }
}U;
vector<int>an;
void dfs(int x){
    while(it[x]<SZ(e[x])){
        int me=it[x];
        it[x]++;
        dfs(e[x][me]);
        an.PB(e[x][me]);
    }
}
int main(){
    DRI(n);
    U.init(4900);
    char s[10];
    REP(i,n){
        RS(s);
        U.uu(get(s[0])*70+get(s[1]),get(s[1])*70+get(s[2]));
        out[get(s[0])*70+get(s[1])]++;
        in[get(s[1])*70+get(s[2])]++;
        e[get(s[1])*70+get(s[2])].PB(get(s[0])*70+get(s[1]));
    }
    int cnt=0;
    REP(i,4900){
        if((in[i]||out[i])&&U.find(i)==i)cnt++;
    }
    if(cnt>1)puts("NO");
    else{
        int st=-1,ed=-1;
        REP(i,4900){
            if(in[i]+1==out[i]){
                if(st!=-1){
                    puts("NO");
                    return 0;
                }
                st=i;
            }
            else if(in[i]==out[i]+1){
                if(ed!=-1){
                    puts("NO");
                    return 0;
                }
                ed=i;
            }
            else if(in[i]!=out[i]){
                puts("NO");
                return 0;
            }
        } 
        puts("YES");
        if(ed==-1){
            ed=4899;
            while(!out[ed])ed--;
        }
        dfs(ed);
        an.PB(ed);
        putchar(to(an[0]/70));
        REP(i,SZ(an)){
            putchar(to(an[i]%70));
        }
        puts("");
    }
    return 0;
}