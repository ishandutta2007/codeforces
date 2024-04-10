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
char s[1000000];
int main(){
    int i,j,k,n,flag1=0,flag2=0;
    gets(s);
    n=atoi(s);
    for(i=0;i<n;i++){
        flag1=flag2=0;
        gets(s);
        int len=strlen(s);
        if(strncmp(s,"miao.",5)==0)flag1=1;
        if(len>=5&&strncmp(s+len-5,"lala.",5)==0)flag2=1;
        if(flag1&&flag2)puts("OMG>.< I don't know!"); 
        else if(flag1)puts("Rainbow's");
        else if(flag2)puts("Freda's");
        else puts("OMG>.< I don't know!");
    }
    return 0;
}