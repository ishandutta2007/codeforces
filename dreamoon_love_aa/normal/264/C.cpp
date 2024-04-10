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
#define SIZE 100010
#define MAX 1e18
int c[SIZE],v[SIZE],used[SIZE],tt;
long long all[2][2],ma[SIZE];
void add(int cc,long long v){
    if(cc==all[0][0])all[0][1]=v;
    else if(cc==all[1][0]){
        if(v<=all[0][1])all[1][1]=v;
        else{
            all[1][0]=all[0][0];
            all[1][1]=all[0][1];
            all[0][0]=cc;
            all[0][1]=v;
        }
    }
    else{
        if(!all[0][0]||v>all[0][1]){
            all[1][0]=all[0][0];
            all[1][1]=all[0][1];
            all[0][0]=cc;
            all[0][1]=v;
        }
        else if(!all[1][0]||v>all[1][1]){
            all[1][0]=cc;
            all[1][1]=v;
        }
    }
}
int main(){
    int i,j,k,n,q;
    long long a,b,an;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)scanf("%d",&v[i]);
    for(i=0;i<n;i++)scanf("%d",&c[i]);
    while(q--){
        an=0;
        tt++;
        all[0][0]=all[1][0]=0;
        scanf("%I64d%I64d",&a,&b);
        for(i=0;i<n;i++){
            long long next=b*v[i];
            if(used[c[i]]==tt){
                next=max(next,ma[c[i]]+a*v[i]);
            }
            if(all[0][0]&&all[0][0]!=c[i]){
                next=max(next,all[0][1]+b*v[i]);
            }
            else if(all[1][0]&&all[1][0]!=c[i])next=max(next,all[1][1]+b*v[i]);
            if(used[c[i]]!=tt||next>ma[c[i]]){
                used[c[i]]=tt;
                ma[c[i]]=next;
                add(c[i],next);
            }
            an=max(an,next);
        }
        printf("%I64d\n",an);
    }
    return 0;
}