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
int len,d[111],dn,k,num[888888];
char s[111];
bool non[222222];
vector<int>de[26];
void init(int id,int L,int R){
    num[id]=(R-L+1);
    if(L==R)return;
    int MM=(L+R)/2;
    init(id*2,L,MM);
    init(id*2+1,MM+1,R);
}
int erase(int id,int L,int R,int x){
    num[id]--;
    if(L==R){
        return L;
    }
    int MM=(L+R)/2;
    if(num[id*2]>=x){
        return erase(id*2,L,MM,x);
    }
    else{
        return erase(id*2+1,MM+1,R,x-num[id*2]);
    }
}
void go(int x,vector<int>& a){
    if(a.size()==0)return;
    dn=0;
    int i;
    for(i=0;i<len;i++)
        if(s[i]=='a'+x)d[dn++]=i;
    init(1,0,dn*k-1);
    for(i=0;i<(int)a.size();i++){
        int tmp=erase(1,0,dn*k-1,a[i]);
        non[tmp/dn*len+d[tmp%dn]]=1;
    }
}
int main(){
    int i,j,n;
    scanf("%d%s",&k,s);
    len=strlen(s);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x;
        char c[4];
        scanf("%d%s",&x,c);
        de[c[0]-'a'].pb(x);
    }
    for(i=0;i<26;i++)go(i,de[i]);
    for(i=0;i<len*k;i++){
        if(!non[i])putchar(s[i%len]);
    }
    puts("");
    return 0;
}