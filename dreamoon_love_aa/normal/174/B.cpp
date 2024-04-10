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
char s[1234567];
int d[1234567],dn;
int main(){
    int i,j,k,n,last=0;
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            d[dn++]=i-last;
            last=i+1;
        }
    }
    d[dn++]=i-last;
    if(dn<=1)puts("NO");
    else{
        if(d[0]>8|d[0]<1||d[dn-1]<1||d[dn-1]>3)puts("NO");
        else{
            for(i=1;i<dn-1;i++){
                if(d[i]<2||d[i]>11)break;
            }
            if(i<dn-1)puts("NO");
            else{
                puts("YES");
                int now=0;
                int len=d[0]+1,next;
                for(i=0;i<dn-1;i++){
                    if(d[i+1]>=4)len+=3,next=d[i+1]-3;
                    else len+=d[i+1]-1,next=1;
                    for(j=0;j<len;j++)printf("%c",s[now+j]);
                    if(i==dn-2)printf("%c",s[now+len]);
                    puts("");
                    now+=len;
                    len=next+1;
                }
            }
        }
    }
    return 0;
}