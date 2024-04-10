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
char s[22222];
int d[128];
int main(){
    int i,j,k,n;
    scanf("%s",s);
    for(i=0;s[i];i++)d[s[i]]++;
    scanf("%s",s);
    for(i=0;s[i];i++)d[s[i]]++;
    scanf("%s",s);
    for(i=0;s[i];i++)d[s[i]]--;
    for(i=0;i<128;i++)
        if(d[i])break;
    puts(i==128?"YES":"NO");
    return 0;
}