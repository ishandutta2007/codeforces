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
#define SIZE 100010
char s[SIZE],an[SIZE];
int len,d[SIZE],ann;
int main(){
    int i,j,k,n,x=0,dn;
    gets(s);
    len=strlen(s);
    scanf("%d",&n);
    if(n>(long long)len*(len+1)/2){
        puts("No such line.");
        return 0;
    }
    for(i=0;i<len;i++)d[i]=i;
    dn=len;
    while(1){
        long long alpha[26]={};
        int num[26]={};
        for(i=0;i<dn;i++){
            alpha[s[d[i]+x]-'a']+=len-d[i]-x;
            num[s[d[i]+x]-'a']++;
        }
        for(i=0;i<26;i++){
            if(n<=alpha[i]){
                an[ann++]=i+'a';
                if(n<=num[i]){
                    puts(an);
                    return 0;
                }
                else{
                    n-=num[i];
                    int ddn=0;
                    for(j=0;j<dn;j++)
                        if(s[d[j]+x]==i+'a'&&s[d[j]+x+1])d[ddn++]=d[j];
                    x++;
                    dn=ddn;
                    break;
                }
            }
            else n-=alpha[i];
        }
    }
    return 0;
}