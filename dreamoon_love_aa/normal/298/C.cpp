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
char s[2][1024];
int one[2];
int main(){
    int i,j,k,n,len[2];
    scanf("%s%s",s[0],s[1]);
    for(i=0;i<2;i++)len[i]=strlen(s[i]);
    for(i=0;i<2;i++)
        for(j=0;j<len[i];j++)
            if(s[i][j]=='1')one[i]++;
    if(one[0]%2==1)one[0]++;
    puts(one[0]>=one[1]?"YES":"NO");
    return 0;
}