#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int d[10],n,k,change[10];
char an[10010],now[10010],s[10010];
int Go(int x){
    memset(change,0,sizeof(change));
    if(d[x]>k){
        return 0;
        change[x]=d[x]-k;
        return d[x]-k;
    }
    else if(d[x]<k){
        int an=0,i;
        int dif=k-d[x];
        for(i=1;;i++){
            if(x+i<10){
                an+=min(dif,d[x+i])*i;
                change[x+i]=min(dif,d[x+i]);
                dif-=min(dif,d[x+i]);
            }
            if(dif==0)return an;
            if(x-i>=0){
                an+=min(dif,d[x-i])*i;
                change[x-i]=min(dif,d[x-i]);
                dif-=min(dif,d[x-i]);
            }
            if(dif==0)return an;
        }
    }
    return 0;
}
void Do(int x){
    strcpy(now,s);
    int i;
    if(d[x]>k){
        return;
        if(x){
            for(i=0;change[x];i++)
                if(now[i]==x+'0')now[x]--,change[x]--;
        }
        else{
            for(i=n-1;change[x];i--)
                if(now[i]==x+'0')now[x]++,change[x]--;
        }
    }
    else if(d[x]<k){
        for(i=0;i<n;i++){
            if(now[i]>x+'0'){
                if(change[now[i]-'0']){
                    change[now[i]-'0']--;
                    now[i]=x+'0';
                }
            }
        }
        for(i=n-1;i>=0;i--){
            if(now[i]<x+'0'){
                if(change[now[i]-'0']){
                    change[now[i]-'0']--;
                    now[i]=x+'0';
                }
            }
        }
    }
}
int main(){
    int i,j,mi=100000000;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(i=0;i<n;i++)d[s[i]-'0']++;
    for(i=0;i<10;i++){
        int tmp=Go(i);
        Do(i);
        if(tmp<mi||(tmp==mi&&strcmp(now,an)<0)){
            mi=tmp;
            strcpy(an,now);
        }
    }
    printf("%d\n",mi);
    puts(an);
    return 0;
}