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
const int MM = 4e5;
LL an;
int a[SIZE];
int d[SIZE][2];
int cnt[SIZE],used[SIZE],tt;
int ll_side[SIZE],rr_side[SIZE];
void add(int x,int v){
    if(used[x]==tt)cnt[x]+=v;
    else{
        used[x]=tt;
        cnt[x]=v;
    }
}
int get(int x){
    if(used[x]==tt)return cnt[x];
    return 0;
}
void f(int L,int R){
    if(L==R){if(a[L]==1)an++;return;}
    int mm=(L+R)>>1;
    f(L,mm);f(mm+1,R);
    d[mm][0]=d[mm][1]=a[mm];
    for(int i=mm-1;i>=L;i--){
        d[i][0]=min(d[i+1][0],a[i]);
        d[i][1]=max(d[i+1][1],a[i]);
    }
    d[mm+1][0]=d[mm+1][1]=a[mm+1];
    for(int i=mm+2;i<=R;i++){
        d[i][0]=min(d[i-1][0],a[i]);
        d[i][1]=max(d[i-1][1],a[i]);
    }
    for(int i=mm;i>=L;i--){
        int h=d[i][1]-d[i][0];
        if(i+h>mm&&i+h<=R&&d[i+h][0]>d[i][0]&&d[i+h][1]<d[i][1]&&rr_side[i]>=i+h&&d[i][0]==1)an++;
    }
    REPP(i,mm+1,R+1){
        int h=d[i][1]-d[i][0];
        if(i-h<=mm&&i-h>=L&&d[i-h][0]>d[i][0]&&d[i-h][1]<d[i][1]&&ll_side[i]<=i-h&&d[i][0]==1)an++;
    }
    int ll=mm+1,rr=mm;
    tt++;
    for(int i=mm;i>=L;i--){
        while(rr+1<=R&&rr+1<=rr_side[i]&&d[rr+1][0]>d[i][0]){
            rr++;
            add(rr-d[rr][1]+MM,1);
        }
        while(rr>=ll&&rr>rr_side[i]){
            add(rr-d[rr][1]+MM,-1);
            rr--;
        }
        while(ll<=rr&&d[ll][1]<d[i][1]){
            add(ll-d[ll][1]+MM,-1);
            ll++;
        }
        if(d[i][0]==1){
            an+=get(i-d[i][0]+MM);
        }
    }
    ll=mm+1,rr=mm;
    tt++;
    for(int i=mm;i>=L;i--){
        if(d[i][0]==1)break;
        int rd=i+d[i][1]-1;
        if(rd<=R&&rd>mm&&rr_side[i]>=rd&&d[rd][1]<d[i][1])an++;
    }
}
int cc[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        DRI(v);
        a[i+1]=v;
    }
    {
        int it=1;
        for(int i=1;i<=n;i++){
            cc[a[i]]++;
            while(cc[a[i]]>1){
                cc[a[it]]--;
                it++;
            }
            ll_side[i]=it;
        }
    }
    {
        MS0(cc);
        int it=n;
        for(int i=n;i>0;i--){
            cc[a[i]]++;
            while(cc[a[i]]>1){
                cc[a[it]]--;
                it--;
            }
            rr_side[i]=it;
        }
    }
    f(1,n);
    cout<<an<<endl;
    return 0;
}