#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
#define P_MAX 1000000
#define MAX 10000000000000ll
using namespace std;
long long a[8],pro[1<<8];
int bit_cnt[1<<8];
vector<long long>pp;
bitset<P_MAX>p;
map<long long,int>H;
int N,an;
int qq(long long x){
    if(H.count(x))return H[x];
    long long X=x;
    int res=0;
    for(int i=0;i<SZ(pp)&&pp[i]*pp[i]<=x;i++){
        while(x%pp[i]==0){
            x/=pp[i];
            res++;
        }
    }
    if(x!=1)res++;
    return H[X]=res;
}
int qq2(long long x){
    if(H.count(x)){
        int tmp=H[x];
        if(tmp==1)return 0;
        return tmp;
    }
    long long X=x;
    int res=0;
    for(int i=0;i<SZ(pp)&&pp[i]*pp[i]<=x;i++){
        while(x%pp[i]==0){
            x/=pp[i];
            res++;
        }
    }
    if(x!=1)res++;
    H[X]=res;
    if(res==1)return 0;
    return res;

}
void dfs(int x,int mask,int v,int head){
    if(x==-1){
        if(head==1)an=min(an,v);
        else an=min(an,v+1);
        return;
    }
    if(!((mask>>x)&1)){
        v++;
        head++;
    }
    REP(i,1<<x){
        if(!i){
            dfs(x-1,mask,v+qq2(a[x]),head);
        }
        else if(!(mask&i)&&a[x]%pro[i]==0){
            dfs(x-1,mask|i,v+bit_cnt[i]+qq(a[x]/pro[i]),head);
        }
    }
}
int main(){
    for(int i=3;i<1000;i+=2){
        for(int j=i*i;j<P_MAX;j+=i+i)p[j]=1;
    }
    pp.PB(2);
    for(int i=3;i<P_MAX;i+=2){
        if(!p[i])pp.PB(i);
    }
    DRI(n);
    N=n;
    REP(i,n)cin>>a[i];
    sort(a,a+n);
    pro[0]=1;
    REPP(i,1,1<<n){
        int k=0;
        while(!((i>>k)&1))k++;
        bit_cnt[i]=bit_cnt[i-(1<<k)]+1;
        long long tmp1=pro[i-(1<<k)];
        long long tmp2=a[k];
        if(tmp1>MAX/tmp2)pro[i]=MAX;
        else pro[i]=tmp1*tmp2;
    }
    an=1000000;
    dfs(n-1,0,0,0);
    printf("%d\n",an);
    return 0;
}