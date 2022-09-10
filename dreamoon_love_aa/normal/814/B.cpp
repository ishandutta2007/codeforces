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
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE],b[SIZE],cnt[SIZE],N;
void print(){
    REP(i,N)printf("%d%c",a[i]," \n"[i==N-1]);
    exit(0);
}
void solve0(int n){
    REP(i,n){
        if(cnt[a[i]]>2){
            REPP(j,1,n+1){
                if(cnt[j]==0){
                    a[i]=j;
                    print();
                }
            }
        }
    }
}
void solve1(int n){
    REP(i,n){
        if(a[i]!=b[i]){
            REPP(j,1,n+1){
                if(!cnt[j]){
                    a[i]=j;
                    print();
                }
            }
        }
    }
}
int tt,used[SIZE];
bool check(int n){
    tt++;
    REP(i,n){
        if(used[a[i]]==tt)return 0;
        used[a[i]]=tt;
    }
    return 1;
}
void solve2(int n){
    VI ids;
    REP(i,n){
        if(a[i]!=b[i])ids.PB(i);
    }
    swap(a[ids[0]],b[ids[0]]);
    if(check(n))print();
    else{
        swap(a[ids[0]],b[ids[0]]);
        swap(a[ids[1]],b[ids[1]]);
        print();
    }
}
int main(){
    DRI(n);
    N=n;
    REP(i,n)RI(a[i]);
    REP(i,n)RI(b[i]);
    int cc=0;
    REP(i,n){
        cnt[a[i]]++;
        cnt[b[i]]++;
        if(a[i]!=b[i])cc++;
    }
    if(cc==0){
        solve0(n);
    }
    else if(cc==1){
        solve1(n);
    }
    else solve2(n);
    return 0;
}