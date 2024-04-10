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
#define pb push_back
#define SIZE 1011
using namespace std;
long long a[SIZE][SIZE],col[SIZE],row[SIZE],cc[SIZE],rr[SIZE];
long long sqr(long long x){return x*x;}
bool fresh(long long& x,long long y){
    if(x>y){
        x=y;
        return 1;
    }
    return 0;
}
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            scanf("%I64d",&a[i][j]);
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    for(i=0;i<=n;i++){
        for(j=1;j<=n;j++){
            rr[i]+=sqr(i*4-(j*4-2))*row[j];
        }
    }
    for(i=0;i<=m;i++){
        for(j=1;j<=m;j++){
            cc[i]+=sqr(i*4-(j*4-2))*col[j];
        }
    }
    long long ma=1000000000000000000ll;
    int an1,an2;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++){
            if(fresh(ma,rr[i]+cc[j]))an1=i,an2=j;
        }
    printf("%I64d\n%d %d\n",ma,an1,an2);
    return 0;
}