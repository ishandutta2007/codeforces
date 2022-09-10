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
#define SIZE 200001
int num;
long long d[SIZE];
void insert(int x,long long v){
    while(x){
        d[x]+=v;
        x-=x&-x;
    }
}
long long get(int x){
    long long res=0;
    while(x<SIZE){
        res+=d[x];
        x+=x&-x;
    }
    return res;
}
int main(){
    int i,j,k,n,ty;
    long long now=0;
    scanf("%d",&n);
    num=1;
    for(i=1;i<=n;i++){
        scanf("%d",&ty);
        if(ty==1){
            int a,x;
            scanf("%d%d",&a,&x);
            a=min(a,num);
            insert(a,x);
            now+=a*x;
        }
        else if(ty==2){
            scanf("%d",&k);
            insert(num,-k);
            num++;
            insert(num,k);
            now+=k;
        }
        else{
            long long tmp=get(num);
            insert(num,-tmp);
            now-=tmp;
            num--;
            insert(num,tmp);
        }
        printf("%.12lf\n",now*1./num);
    }
    return 0;
}