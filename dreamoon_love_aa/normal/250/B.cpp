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
void parse(char s[],vector<string>&d){
    int i,j;
    for(i=0;;i=j+1){
        for(j=i;s[j]!=':'&&s[j];j++);
        char c=s[j];
        s[j]=0;
        d.pb(s+i);
        if(!c)break;
    }
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char s[1024];
        char an[32];
        for(j=0;j<32;j++)an[j]='0';
        scanf("%s",s);
        vector<string>d;
        parse(s,d);
        for(j=0;j<d.size()&&d[j]!="";j++);
        if(j<d.size()){
            d.erase(d.begin()+j);
            while(d.size()<8)d.insert(d.begin()+j,"");
        }
        for(j=0;j<8;j++){
            for(k=1;k<=d[j].size();k++)an[j*4+4-k]=d[j][d[j].size()-k];
        }
        for(j=0;j<32;j++){
            printf("%c",an[j]);
            if(j%4==3&&j!=31)printf(":");
        }
        puts("");
    }
    return 0;
}