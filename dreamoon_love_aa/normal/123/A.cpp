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
bool p[1024];
char s[1024],an[1024];
int d[26];
int main(){
    int i,j,len,ma=0,least,No;
    for(i=2;i<1024;i++)
        if(!p[i])
            for(j=i+i;j<1024;j+=i)p[j]=1;
    scanf("%s",s+1);
    len=strlen(s+1);
    for(i=1;i<=len;i++)d[s[i]-'a']++;
    for(i=0;i<26;i++){
        if(d[i]>ma){
            ma=d[i];
            No=i;
        }
    }
    least=1;
    for(i=max(3,len/2+1);i<=len;i++)
        if(!p[i])least++;
    if(ma<len-least)puts("NO");
    else{
        puts("YES");
        for(i=2;i<=len;i++)
            if(i+i<=len||p[i])an[i]='a'+No,d[No]--;
        for(i=1,j=0;i<=len;i++)
            if(an[i]==0){
                while(d[j]==0)j++;
                d[j]--;
                an[i]='a'+j;
            }
        puts(an+1);
    }
    return 0;
}