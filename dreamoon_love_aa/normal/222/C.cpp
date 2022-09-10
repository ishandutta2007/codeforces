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
#define SIZE 10000001
int a[1000001],b[100001],last[SIZE],dn;
struct data{
    int p,flag;
    data(int _p=0,int _flag=0){p=_p,flag=_flag;}
    bool operator<(const data& b)const{
        return p<b.p||(p==b.p&&flag<b.flag);
    }
}d[SIZE];
bitset<SIZE>p;
int pos(int x){
    if(x<0)return -1;
    return 1;
}
int main(){
    int i,j,n,m;
    for(i=2;i<SIZE;i++){
        if(!p[i]){
            last[i]=i;
            if((long long)i*i>=SIZE)continue;
            for(j=i*i;j<SIZE;j+=i){
                p[j]=1;
                if(!last[j])last[j]=i;
            }
        }
    }
    cin>>n>>m;
    for(i=1;i<=n;i++){
        int x;
        cin>>a[i];
        int now=a[i];
        while(now!=1){
            d[dn++]=data(last[now],i);
            now/=last[now];
        }
    }
    for(i=1;i<=m;i++){
        int x;
        cin>>b[i];
        int now=b[i];
        while(now!=1){
            d[dn++]=data(last[now],-i);
            now/=last[now];
        }
    }
    sort(d,d+dn);
    for(i=0;i<dn;i+=j){
        for(j=1;i+j<dn&&d[i+j].p==d[i].p;j++);
        int k1=i,k2=i+j-1;
        while(k1<k2){
            if(pos(d[k1].flag)*pos(d[k2].flag)==1)break;
            b[-d[k1].flag]/=d[i].p;
            a[d[k2].flag]/=d[i].p;
            k1++;
            k2--;
        }
    }
    printf("%d %d\n",n,m);
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        printf("%d",a[i]);
    }
    puts("");
    for(i=1;i<=m;i++){
        if(i!=1)printf(" ");
        printf("%d",b[i]);
    }
    puts("");
    return 0;
}