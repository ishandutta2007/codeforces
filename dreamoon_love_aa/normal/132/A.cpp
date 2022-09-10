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
char s[128];
int main(){
    int i,j,k,last=0;
    gets(s);
    for(i=0;s[i];i++){
        int d[8];
        for(j=0;j<8;j++){
            d[j]=s[i]&1;
            s[i]>>=1;
        }
        unsigned char tmp=0;
        for(j=0;j<8;j++){
            tmp<<=1;
            tmp+=d[j];
        }
        printf("%d\n",(last-tmp+256)&255);
        last=tmp;

    }
    return 0;
}