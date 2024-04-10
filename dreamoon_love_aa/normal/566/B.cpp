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
// template end here
int a[SIZE],b[SIZE],c[SIZE],cnt[SIZE];
bool used[SIZE];
vector<int>r[SIZE];
set<int>H;
void print_array(vector<int>&arr){
    REP(i,SZ(arr)){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
bool check(int r_id){
    if(b[r_id]==c[r_id]){
        if(a[r_id]==b[r_id]){
            return cnt[c[r_id]]<9;
        }
        else{
            return cnt[c[r_id]]<8;
        }
    }
    else{
        if(a[r_id]!=b[r_id]){
            if(cnt[b[r_id]]==9)return false;
        }
        if(a[r_id]!=c[r_id]){
            if(cnt[c[r_id]]==9)return false;
        }
        return true;
    }
}
int main(){
    DRI(n);
    REP(i,4*n){
        RIII(a[i],b[i],c[i]);
        r[a[i]].PB(i);
        r[b[i]].PB(i);
        r[c[i]].PB(i);
        H.insert(i);
    }
    REP(i,n)cnt[i+1]=4;
    puts("YES");
    vector<int>an;
    while(SZ(H)){
        int me=*H.begin();
        used[me]=1;
        H.erase(me);
        int now[3]={a[me],b[me],c[me]};
        cnt[a[me]]--;
        cnt[b[me]]++;
        cnt[c[me]]++;
        an.PB(me+1);
        REP(k,3){
            int id=now[k];
            REP(i,SZ(r[id])){
                int r_id=r[id][i];
                if(!used[r_id]){
                    if(check(r_id)){
                        H.insert(r_id);
                    }
                    else{
                        if(H.count(r_id))H.erase(r_id);
                    }
                }
            }
        }
    }
    print_array(an);
    assert(SZ(an)==n*4);
    return 0;
}