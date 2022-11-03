#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int mod;

int mPow(int a,int x,int MOD) {
    int ret=1;
    while(x) {
        if (x&1) ret=(1LL*ret*a)%MOD;
        a=(1LL*a*a)%MOD; x>>=1;
    }
    return ret;
}

const int MAXN=2;
int tmp[MAXN][MAXN],N=MAXN;

void mul(int r[MAXN][MAXN],int a[MAXN][MAXN],int b[MAXN][MAXN]) {
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j) {
            long long val=0;
            for(int t=0;t<N;++t)
                val+=1LL*a[i][t]*b[t][j];
            tmp[i][j]=val%mod;
        }
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j)
            r[i][j]=tmp[i][j];
    }
}

void mPow(int r[MAXN][MAXN],int a[MAXN][MAXN],long long x) {
    if (x<0) return;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) r[i][j]=0;
        r[i][i]=1;
    }
    while(x) {
        if (x&1) mul(r,r,a);
        mul(a,a,a); x>>=1;
    }
}

long long get(long long l,long long k) {
    if (l<0) return 0;
    return l/k+1;
}

long long find(long long L,long long R,long long k) {
    long long l=0,r=1000000000002LL;
    while(r-l>1) {
        long long m=(l+r)/2;
        if ((L/m)<=(R/(m+k-1))) r=m;
        else l=m;
    }
    return r;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    long long l,r,k;
    cin >> mod >> l >> r >> k;
    long long val=(r-l+1)/k;
//  while(get(r,val)-get(l-1,val)<k) --val;
    for(int i=1;i<=1000000;++i)
        if (get(r,i)-get(l-1,i)>=k) val=i;
    long long k1=find(l,r,k),val1=r/(k1+k-1);
    if (val1>=val&&get(r,val1)-get(l-1,val1)>=k) val=val1;
//  if (get(r,val1)-get(l-1,val1)<k) cout << "fail\n";
    int mat[2][2]={{1,1},{1,0}};
    if (val<=2) {
        printf("%d\n",1%mod);
        return 0;
    }
    int res[2][2]={0};
    mPow(res,mat,val-2);
    printf("%d\n",(res[0][0]+res[1][0])%mod);
    return 0;
}