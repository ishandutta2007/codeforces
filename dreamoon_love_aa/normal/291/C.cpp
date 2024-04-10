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
using namespace std;
bitset<32>d[100000];
bool compare(bitset<32> A,bitset<32> B){
    for(int i=0;i<32;i++){
        if(A[i]&&!B[i])return 0;
        if(!A[i]&&B[i])return 1;
    }
    return 0;
}
int main(){
    int i,j,k,n,a[4],K;
    scanf("%d%d",&n,&K);
    for(i=0;i<n;i++){
        scanf("%d . %d . %d . %d",&a[0],&a[1],&a[2],&a[3]);
        for(j=0;j<4;j++){
            for(k=0;k<8;k++)
                if((a[j]>>k)&1)d[i][j*8+7-k]=1;
        }
    }
    bitset<32>now;
    now.reset();
    for(i=0;i<31;i++){
        now[i]=1;
        vector<bitset<32> >yo;
        for(j=0;j<n;j++)yo.pb(now&d[j]);
        sort(yo.begin(),yo.end(),compare);
        yo.resize(unique(yo.begin(),yo.end())-yo.begin());
        if(yo.size()==K){
            for(i=0;i<4;i++){
                int tmp=0;
                for(j=0;j<8;j++){
                    if(now[i*8+7-j])tmp|=1<<j;
                }
                if(i)printf(".");
                printf("%d",tmp);
            }
            puts("");
            return 0;
        }
    }
    if(i==31)puts("-1");
    return 0;
}