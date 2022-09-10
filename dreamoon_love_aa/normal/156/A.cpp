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
#define SIZE 6000
char s1[SIZE],s2[SIZE];
int main(){
    int i,j,k,n,len,an=2000000;
    scanf("%s",s1+2000);
    scanf("%s",s2);
    len=strlen(s2);
    for(i=0;i<4000;i++){
        int cnt=0;
        for(j=0;j<len;j++)
            if(s1[i+j]!=s2[j])cnt++;
        an=min(an,cnt);
    }
    printf("%d\n",an);
    return 0;
}