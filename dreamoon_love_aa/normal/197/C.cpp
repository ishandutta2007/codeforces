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
#define SIZE 100005
char s[SIZE];
int d[26],next[SIZE];
int main(){
    int i,j,k,n;
    gets(s);
    n=strlen(s);
    memset(d,-1,sizeof(d));
    for(i=n-1;i>=0;i--){
        for(j=25;j>=0;j--){
            if(d[j]!=-1)break;
        }
        if(j<0)next[i]=-1;
        else next[i]=d[j];
        d[s[i]-'a']=i;
    }
    for(i=25;i>=0;i--)
        if(d[i]>=0)break;
    i=d[i];
    while(i!=-1){
        printf("%c",s[i]);
        i=next[i];
    }
    puts("");
    return 0;
}