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
int d[11],r[4];
vector<string>an;
void dfs(int x,int y,int n,char s[]){
    int i;
    if(4-x>n-y)return;
    if(x==3){
        if(n-y>3)return;
        r[x]=0;
        long long v=0;
        if(s[y]=='0'){
            if(y+1!=n)return;
        }
        else{
            for(i=y;i<n;i++){
                v*=10;
                v+=s[i]-'0';
            }
            r[3]=v;
        }
        if(0<=v&&v<256){
            string ha="";
            for(i=0;i<4;i++){
                if(i)ha+=".";
                char yo[16];
                sprintf(yo,"%d",r[i]);
                ha+=string(yo);
            }
            an.pb(ha);
        }
        return;
    }
    r[x]=0;
    if(s[y]=='0'){
        dfs(x+1,y+1,n,s);
        return;
    }
    for(i=y;i<n&&r[x]<256;i++){
        r[x]*=10;
        r[x]+=s[i]-'0';
        if(r[x]<256)dfs(x+1,i+1,n,s);
    }
}
void go(char s[],int len){
    if(len<4)return;
    dfs(0,0,len,s);
}
void fill(int cnt[],int x){
    while(x){
        cnt[x%10]++;
        x/=10;
    }
}
int main(){
    int i,j,k,kk,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        d[k]=1;
    }
    for(i=10;i<=1000000;i++){
        char s[32];
        sprintf(s,"%d",i);
        int len=strlen(s);
        int cnt[10]={};
        fill(cnt,i);
        for(j=0;j<10;j++){
            if(d[j]&&cnt[j]==0)break;
            if(!d[j]&&cnt[j]>0)break;
        }
        if(j<10)continue;
        for(j=0;j<len;j++)s[len+j]=s[len-1-j];
        s[len+len]=0;
        go(s,len+len);
        for(j=0;j<len-1;j++)s[len+j]=s[len-2-j];
        s[len+len-1]=0;
        go(s,len+len-1);
    }
    if(d[0]){
        for(i=0;i<=9999;i++){
            char s[32];
            sprintf(s,"0%d",i);
            int len=strlen(s);
            int cnt[10]={};
            fill(cnt,i);
            cnt[0]++;
            for(j=1;j<10;j++){
                if(d[j]&&cnt[j]==0)break;
                if(!d[j]&&cnt[j]>0)break;
            }
            if(j<10)continue;
            for(j=0;j<len;j++)s[len+j]=s[len-1-j];
            s[len+len]=0;
            go(s,len+len);
            for(j=0;j<len-1;j++)s[len+j]=s[len-2-j];
            s[len+len-1]=0;
            go(s,len+len-1);
        }
        for(i=0;i<9999;i++){
            char s[32];
            sprintf(s,"00%d",i);
            int len=strlen(s);
            int cnt[10]={};
            fill(cnt,i);
            cnt[0]++;
            for(j=1;j<10;j++){
                if(d[j]&&cnt[j]==0)break;
                if(!d[j]&&cnt[j]>0)break;
            }
            if(j<10)continue;
            for(j=0;j<len;j++)s[len+j]=s[len-1-j];
            s[len+len]=0;
            go(s,len+len);
            for(j=0;j<len-1;j++)s[len+j]=s[len-2-j];
            s[len+len-1]=0;
            go(s,len+len-1);
        }
    }
    printf("%d\n",(int)an.size());
    for(i=0;i<an.size();i++)cout<<an[i]<<endl;
    return 0;
}