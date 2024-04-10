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
int main(){
    int i,j,k,n,len,x,y,z,an=-1;
    char s[128],cc;
    gets(s);
    len=strlen(s);
    for(i=1;i<len-1&&i<8;i++)
        for(j=i+1;j<len&&j<i+8;j++){
            if(len-j>8)continue;
            if(i!=1&&s[0]=='0')continue;
            if(i+1!=j&&s[i]=='0')continue;
            if(j+1!=len&&s[j]=='0')continue;
            cc=s[i];
            s[i]=0;
            x=atoi(s);
            s[i]=cc;
            cc=s[j];
            s[j]=0;
            y=atoi(s+i);
            s[j]=cc;
            z=atoi(s+j);
            if(x>1000000||y>1000000||z>1000000)continue;
            an=max(an,x+y+z);
        }
    printf("%d\n",an);
    return 0;
}