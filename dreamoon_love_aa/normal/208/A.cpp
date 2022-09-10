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
    int i,j,k=0,n;
    char s[1000],an[1000];
    gets(s);
    for(i=0;s[i];i++){
        if(strncmp(s+i,"WUB",3)==0){
            for(j=0;j<3;j++)s[i+j]=0;
            i+=2;
        }
    }
    for(j=0;j<i;j++){
        if(s[j]==0){
            if(j&&s[j-1])printf(" ");
        }
        else putchar(s[j]);
    }
    puts("");
    return 0;
}