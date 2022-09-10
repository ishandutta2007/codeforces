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
char s[1000],t[1000];
int to(char c){
    if(c>='0'&&c<='9')return c-'0';
    return c-'A'+10;
}
int big(char s[]){
    int res=0;
    for(int i=0;s[i];i++)res=max(res,to(s[i]));
    return res;
}
int parse(char ss[],int b){
    int res=0,i;
    for(i=0;ss[i];i++){
        res*=b;
        res+=to(ss[i]);
        if(res>100)res=100;
    }
    return res;
}
vector<int>an;
int main(){
    int i,j,k,n;
    scanf("%s",s);
    for(i=0;s[i]!=':';i++);
    strcpy(t,s+i+1);
    s[i]=0;
    int bb=max(big(s),big(t));
    for(i=max(bb+1,2);i<500;i++){
        if(parse(s,i)<24&&parse(t,i)<60)an.pb(i);
    }
    if(an.size()>400)puts("-1");
    else if(an.size()==0)puts("0");
    else{
        for(i=0;i<an.size();i++){
            if(i)putchar(' ');
            printf("%d",an[i]);
        }
        puts("");
    }
    return 0;
}